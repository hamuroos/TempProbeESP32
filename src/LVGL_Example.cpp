#include "LVGL_Example.h"
#include "LVGL_Music.h"

#include <demos/lv_demos.h>

#include "Temperature.h"
// #include <demos/music/lv_demo_music_main.h>
// #include <demos/music/lv_demo_music_list.h>

#include "time.h"
#include "AWS_secret.h"

#include <HTTPClient.h>

const char *ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 25200; // GMT +7 for Bangkok
const int daylightOffset_sec = 0;
/**********************
 *      TYPEDEFS
 **********************/
typedef enum
{
  DISP_SMALL,
  DISP_MEDIUM,
  DISP_LARGE,
} disp_size_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void Onboard_create(lv_obj_t *parent);
static void Music_create(lv_obj_t *parent);
static void color_changer_create(lv_obj_t *parent);

static void Temp_create(lv_obj_t *parent);
static void API_tester_create(lv_obj_t *parent);

static void color_changer_event_cb(lv_event_t *e);
static void color_event_cb(lv_event_t *e);
static void ta_event_cb(lv_event_t *e);
static void birthday_event_cb(lv_event_t *e);
static void calendar_event_cb(lv_event_t *e);
void IRAM_ATTR example1_increase_lvgl_tick(lv_timer_t *t);

static void event_handler_Start_btn(lv_event_t *e);
static void Wifi_btn_event_cb(lv_event_t *e);

static void API_btn_event_cb(lv_event_t *e);
static void SKU_dropdown_event_cb(lv_event_t *e);
static void batch_change_event_cb(lv_event_t *e);
static void addSKUnonDup(const char *item);
static void addSKUList();
static void clearSKUlist();
static void getSKUFromAPI();

/**********************
 *  STATIC VARIABLES
 **********************/
static disp_size_t disp_size;

static lv_obj_t *tv;
static lv_obj_t *calendar;
lv_style_t style_text_muted;
lv_style_t style_title;
static lv_style_t style_icon;
static lv_style_t style_bullet;

static lv_style_t st;

static lv_obj_t *chart1;
static lv_obj_t *chart2;
static lv_obj_t *chart3;

static lv_chart_series_t *ser1;
static lv_chart_series_t *ser2;
static lv_chart_series_t *ser3;
static lv_chart_series_t *ser4;

static const lv_font_t *font_large;
static const lv_font_t *font_normal;

static lv_timer_t *auto_step_timer;
static lv_timer_t *auto_temp_timer;

static lv_color_t original_screen_bg_color;

static lv_timer_t *meter2_timer;

lv_obj_t *Temp_CC;

lv_obj_t *SD_Size;
lv_obj_t *FlashSize;
lv_obj_t *BAT_Volts;
lv_obj_t *Board_angle;
lv_obj_t *RTC_Time;
lv_obj_t *Wireless_Scan;
lv_obj_t *Backlight_slider;

// extern const lv_font_t ThaiSansNeue_Bold_25;
LV_FONT_DECLARE(Sarabun);

/////////////////// V2 added /////////////////////////

lv_obj_t *arc;

lv_obj_t *Start_btn;
lv_obj_t *btn_label;
bool checked;

float previous_temp = 0.0;
float temp_threshold = 0.1;
int stableCount = 0;
bool stop_reading = true;

bool stable_check = false;
float stable_temp = 0.0;

void IRAM_ATTR Temp_Read(lv_timer_t *t);
const int stableReadings = 10; // Number of stable readings before stopping

/////////////////// V3 added /////////////////////////
// static void buildSettings();

lv_obj_t *Wifi_label;

static lv_obj_t *settings;
static lv_obj_t *settingBtn;
static lv_obj_t *settingCloseBtn;
static lv_obj_t *settingWiFiSwitch;
static lv_obj_t *wfList;
static lv_obj_t *settinglabel;
static lv_obj_t *mboxConnect;
static lv_obj_t *mboxTitle;
static lv_obj_t *mboxPassword;
static lv_obj_t *mboxConnectBtn;
static lv_obj_t *mboxCloseBtn;
static lv_obj_t *keyboard;
static lv_obj_t *popupBox;
static lv_obj_t *popupBoxCloseBtn;
static lv_timer_t *timer;

static void scanWIFITask(void *pvParameters);
static void timerForNetwork(lv_timer_t *timer);
static void list_event_handler(lv_event_t *e);
static void text_input_event_cb(lv_event_t *e);

void beginWIFITask(void *pvParameters);

static void popupMsgBox(String title, String msg);
static void showingFoundWiFiList();
void updateLocalTime();

TaskHandle_t ntScanTaskHandler, ntConnectTaskHandler;
std::vector<String> foundWifiList;

static int foundNetworks = 0;
unsigned long networkTimeout = 10 * 1000;
String ssidName, ssidPW;

typedef enum
{
  NONE,
  NETWORK_SEARCHING,
  NETWORK_CONNECTED_POPUP,
  NETWORK_CONNECTED,
  NETWORK_CONNECT_FAILED
} Network_Status_t;
Network_Status_t networkStatus = NONE;

/////////////// V4 Added ///////////////////////
#include <SPI.h>

char SSD_Name[100][100];
char FFile_Name[100][100];

static void SD_create(lv_obj_t *parent);

static lv_obj_t *sdList;
uint16_t File_CNT;

static void Filelist_event_handler(lv_event_t *e);
static void Read_btn_event_cb(lv_event_t *e);

std::vector<String> foundFileList;

static lv_obj_t *Read_main;
static lv_obj_t *File_label;
static lv_obj_t *Read_CloseBtn;

static lv_obj_t *File_ta;

////////////////////////////////////////////////

/////////////// V6 Added ///////////////////////
// Save data and create payload and read
#include <ArduinoJson.h>

#define LV_INDEV_DEF_LONG_PRESS_TIME 400;
static void Del_popupMsgBox(String title, String msg);

static lv_obj_t *Del_popupBox;
static lv_obj_t *Del_popupBoxCloseBtn;
static lv_obj_t *Del_Btn;
StaticJsonDocument<200> JsonDoc;

String date_time;
// String FN_date_time;

String Hold_filename;

String FN_date_time = "/Wifi_not_Connected.txt";

lv_obj_t *SKU_label;
lv_obj_t *Bat_bar;
lv_obj_t *Bat_text;

/////////////// V8 Screentimeout ///////////////////////
static lv_timer_t *timeout_timer;
void IRAM_ATTR screen_timeout(lv_timer_t *t);

uint8_t BU_LCD_Backlight = LCD_Backlight;

int C_BAT_percent = 0;

// Variables for smoothing the readings
const int numReadings = 50;    // Number of readings for averaging
float B_readings[numReadings]; // Array to store readings
int readIndex = 0;             // Index of the current reading
float total = 0;               // Sum of the readings
float average = 0;             // Average of the readings

/////////////// V12 Change Package + Calibrate Screen ///////////////////////
static lv_obj_t *Calibrate;

static lv_obj_t *Cal;
static lv_obj_t *CalBtn;
static lv_obj_t *CalCloseBtn;
static lv_obj_t *Temp_Cal;

static lv_obj_t *CalPlusBtn;
static lv_obj_t *CalMinBtn;
static lv_obj_t *CalSaveBtn;
static lv_obj_t *CalResetBtn;

static void Calibrate_btn_event_cb(lv_event_t *e);

float Cal_temp = 0.0;

#include <Preferences.h>
Preferences preferences;

lv_obj_t *spinner;
static lv_obj_t *PWBtn;
static lv_obj_t *PWCloseBtn;
static lv_obj_t *ShutdownBtn;
static lv_obj_t *ShutdownCanBtn;
static lv_obj_t *Power;

static lv_obj_t *APIBtn;
static lv_obj_t *APISendBtn;
static lv_obj_t *BatchUpBtn;
static lv_obj_t *BatchDownBtn;

//////////////////////////////////////////////////////////

static void networkConnector()
{
  xTaskCreate(beginWIFITask,
              "beginWIFITask",
              4096,
              NULL,
              1,
              &ntConnectTaskHandler);
}

static lv_timer_t *sleep_timer;
void IRAM_ATTR sleep_mode(lv_timer_t *t);

//////// ASW MQTT ////////////////////////////

#include <WiFiClientSecure.h>
#include <MQTTClient.h>

time_t rawtime;

///////////////////////////////////////////////

void Lvgl_Example1(void)
{

  disp_size = DISP_SMALL;

  font_large = LV_FONT_DEFAULT;
  font_normal = LV_FONT_DEFAULT;

  lv_coord_t tab_h;
  tab_h = 45;
#if LV_FONT_MONTSERRAT_18
  font_large = &lv_font_montserrat_18;
#else
  LV_LOG_WARN("LV_FONT_MONTSERRAT_18 is not enabled for the widgets demo. Using LV_FONT_DEFAULT instead.");
#endif
#if LV_FONT_MONTSERRAT_12
  font_normal = &lv_font_montserrat_12;
#else
  LV_LOG_WARN("LV_FONT_MONTSERRAT_12 is not enabled for the widgets demo. Using LV_FONT_DEFAULT instead.");
#endif

  lv_style_init(&style_text_muted);
  lv_style_set_text_opa(&style_text_muted, LV_OPA_90);

  lv_style_init(&style_title);
  lv_style_set_text_font(&style_title, font_large);

  lv_style_init(&style_icon);
  lv_style_set_text_color(&style_icon, lv_theme_get_color_primary(NULL));
  lv_style_set_text_font(&style_icon, font_large);

  lv_style_init(&style_bullet);
  lv_style_set_border_width(&style_bullet, 0);
  lv_style_set_radius(&style_bullet, LV_RADIUS_CIRCLE);

  tv = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, tab_h);

  lv_obj_set_style_text_font(lv_scr_act(), font_normal, 0);

  if (disp_size == DISP_LARGE)
  {
    lv_obj_t *tab_btns = lv_tabview_get_tab_btns(tv);
    lv_obj_set_style_pad_left(tab_btns, LV_HOR_RES / 2, 0);
    lv_obj_t *logo = lv_img_create(tab_btns);
    LV_IMG_DECLARE(img_lvgl_logo);
    lv_img_set_src(logo, &img_lvgl_logo);
    lv_obj_align(logo, LV_ALIGN_LEFT_MID, -LV_HOR_RES / 2 + 25, 0);

    lv_obj_t *label = lv_label_create(tab_btns);
    lv_obj_add_style(label, &style_title, 0);
    lv_label_set_text(label, "LVGL v8");
    lv_obj_align_to(label, logo, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);

    label = lv_label_create(tab_btns);
    lv_label_set_text(label, "Widgets demo");
    lv_obj_add_style(label, &style_text_muted, 0);
    lv_obj_align_to(label, logo, LV_ALIGN_OUT_RIGHT_BOTTOM, 10, 0);
  }

  lv_obj_t *t1 = lv_tabview_add_tab(tv, "Temp Measure");
  lv_obj_t *t2 = lv_tabview_add_tab(tv, "Onbooard");
  lv_obj_t *t3 = lv_tabview_add_tab(tv, "SD card");

  // create test page for API and MQTT
  lv_obj_t *t4 = lv_tabview_add_tab(tv, "APIMQ");

  Temp_create(t1);
  Onboard_create(t2);
  SD_create(t3);
  API_tester_create(t4);
  // Music_create(t1);
  // color_changer_create(t3);
}

void Lvgl_Example1_close(void)
{
  /*Delete all animation*/
  lv_anim_del(NULL, NULL);

  lv_timer_del(meter2_timer);
  meter2_timer = NULL;

  lv_obj_clean(lv_scr_act());

  lv_style_reset(&style_text_muted);
  lv_style_reset(&style_title);
  lv_style_reset(&style_icon);
  lv_style_reset(&style_bullet);
}
/**********************
 *  SD CARDFUNCTIONS
 **********************/

void LVGL_Search_SD()
{
  File_CNT = Folder_retrieval_C("/", SSD_Name, 100);

  // printf(SSD_Name.c_str());

  if (File_CNT)
  {
    for (int i = 0; i < File_CNT; i++)
    {
      strcpy(FFile_Name[i], SSD_Name[i]);

      // String item = (FFile_Name[i]);
      // String item = SSD_Name[i];

      // String item = String(SSD_Name[i])+"/"+String(FFile_Name[i]) ;

      String item = "/" + String(FFile_Name[i]);

      foundFileList.push_back(item);
    }
  }
}
// static lv_obj_t * main_SD;

static void buildRead(void)
{
  Read_main = lv_obj_create(lv_scr_act());
  // lv_obj_add_style(settings, &border_style, 0);
  lv_obj_set_size(Read_main, 230, 280);
  lv_obj_align(Read_main, LV_ALIGN_TOP_RIGHT, -5, 20);

  File_label = lv_label_create(Read_main);
  lv_label_set_text(File_label, "Text");
  lv_obj_align(File_label, LV_ALIGN_TOP_LEFT, 0, 30);

  File_ta = lv_textarea_create(Read_main); // Create a text area on the active screen
  lv_obj_set_size(File_ta, 200, 200);      // Set the size of the text area
  lv_obj_align(File_ta, LV_ALIGN_CENTER, 0, 20);
  // lv_obj_set_scrollbar_mode(File_ta, LV_SCROLLBAR_MODE_ACTIVE);
  // lv_obj_set_scrollbar_mode(File_ta, LV_SCROLLBAR_MODE_ON);
  // lv_obj_set_scroll_propagation(File_ta, 1); // Enable scroll propagation

  Read_CloseBtn = lv_btn_create(Read_main);
  lv_obj_set_size(Read_CloseBtn, 30, 30);
  lv_obj_align(Read_CloseBtn, LV_ALIGN_TOP_LEFT, 0, -10);
  lv_obj_add_event_cb(Read_CloseBtn, Read_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_t *btnSymbol = lv_label_create(Read_CloseBtn);
  lv_label_set_text(btnSymbol, LV_SYMBOL_CLOSE);
  lv_obj_center(btnSymbol);
}

static void SD_create(lv_obj_t *parent)
{
  buildRead();

  lv_obj_move_background(Read_main);

  LVGL_Search_SD();

  if (File_CNT)
  {
    sdList = lv_list_create(parent);
    lv_obj_set_size(sdList, 200, 240);
    // lv_obj_align_to(parent , LV_ALIGN_TOP_LEFT, -5, 30);
    lv_obj_align(sdList, LV_ALIGN_TOP_LEFT, 0, 10);

    for (std::vector<String>::iterator item = foundFileList.begin(); item != foundFileList.end(); ++item)
    {
      lv_obj_t *btn = lv_list_add_btn(sdList, LV_SYMBOL_FILE, (*item).c_str());
      lv_obj_add_event_cb(btn, Filelist_event_handler, LV_EVENT_ALL, NULL);
      // lv_obj_set_event_cb(btn,Filelist_event_handler);
    }
  }

  else
  {

    lv_obj_t *label = lv_label_create(parent);
    lv_label_set_text(label, "No File Found");
    // lv_obj_set_size(label, LV_PCT(100), LV_PCT(100));

    lv_obj_set_size(label, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
  }
}

static void Filelist_event_handler(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *obj = lv_event_get_target(e);

  if (code == LV_EVENT_SHORT_CLICKED)
  {

    String selectedItem = String(lv_list_get_btn_text(sdList, obj));
    // printf(selectedItem.c_str());

    // Serial.println(selectedItem);

    // String filename = "/"+ (selectedItem);

    // Serial.println(filename);
    // printf((SSD_Name+selectedItem).c_str());
    if (SD_MMC.exists(selectedItem.c_str()))
    {
      printf("File exists. \n");
    }
    else
    {
      printf("File does not exist. \n");
    }

    File file = SD_MMC.open(selectedItem.c_str(), FILE_READ);

    if (!file)
    {
      printf("Failed to open file for reading %s \n", selectedItem.c_str());
      return;
    }

    lv_obj_move_foreground(Read_main);

    // lv_label_set_text(File_label,"Loading.....");
    lv_textarea_set_placeholder_text(File_ta, "Loading...");
    lv_label_set_text(File_label, selectedItem.c_str());

    String content = "";

    while (file.available())
    {
      content += (char)file.read();
    }
    // lv_label_set_text(File_label,"Finished");
    lv_textarea_set_placeholder_text(File_ta, "Finished");
    delay(5);

    file.close();
    // lv_label_set_text(File_label,content.c_str());
    // lv_textarea_set_placeholder_text(File_ta,content.c_str());
    lv_textarea_set_text(File_ta, content.c_str());
    lv_obj_set_scrollbar_mode(File_ta, LV_SCROLLBAR_MODE_ACTIVE);
    // lv_textarea_set_cursor_pos(File_ta, 0);
    lv_obj_scroll_to(File_ta, 0, 0, LV_ANIM_OFF);
    // lv_refr_now(NULL);
  }

  else if (code == LV_EVENT_LONG_PRESSED)
  {
    String selectedItem = String(lv_list_get_btn_text(sdList, obj));
    Hold_filename = selectedItem;
    Del_popupMsgBox("Delete File", "Do you want to delete file?");
  }
}
static void Read_btn_event_cb(lv_event_t *e)
{

  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *btn = lv_event_get_target(e);

  if (code == LV_EVENT_CLICKED)
  {
    if (btn == Read_CloseBtn)
    {
      lv_obj_move_background(Read_main);
      // lv_obj_clear_flag(Read_main, LV_OBJ_FLAG_HIDDEN);
      // lv_label_set_text(File_label, "");
    }
  }
}

static void Del_popupMsgBox(String title, String msg)
{

  // #define LCD_WIDTH   240 //LCD width
  // #define LCD_HEIGHT  320 //LCD height

  if (Del_popupBox != NULL)
  {
    lv_obj_del(Del_popupBox);
  }

  Del_popupBox = lv_obj_create(lv_scr_act());
  // lv_obj_add_style(popupBox, &popupBox_style, 0);
  lv_obj_set_size(Del_popupBox, 180, 160);
  lv_obj_center(Del_popupBox);

  lv_obj_t *Del_popupTitle = lv_label_create(Del_popupBox);
  lv_label_set_text(Del_popupTitle, title.c_str());
  lv_obj_set_width(Del_popupTitle, 240 * 2 / 3 - 50);
  lv_obj_align(Del_popupTitle, LV_ALIGN_TOP_LEFT, 0, 0);

  lv_obj_t *Del_popupMSG = lv_label_create(Del_popupBox);
  lv_obj_set_width(Del_popupMSG, 240 * 2 / 3 - 50);
  lv_label_set_text(Del_popupMSG, msg.c_str());
  lv_obj_align(Del_popupMSG, LV_ALIGN_TOP_LEFT, 0, 40);

  Del_popupBoxCloseBtn = lv_btn_create(Del_popupBox);
  lv_obj_add_event_cb(Del_popupBoxCloseBtn, Wifi_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_align(Del_popupBoxCloseBtn, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
  lv_obj_t *btnLabel = lv_label_create(Del_popupBoxCloseBtn);
  lv_label_set_text(btnLabel, "Cancel");
  lv_obj_center(btnLabel);

  Del_Btn = lv_btn_create(Del_popupBox);
  lv_obj_add_event_cb(Del_Btn, Wifi_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_align(Del_Btn, LV_ALIGN_BOTTOM_LEFT, 0, 0);
  lv_obj_t *DbtnLabel = lv_label_create(Del_Btn);
  lv_label_set_text(DbtnLabel, "Delete");
  lv_obj_center(DbtnLabel);
}

////////////////////////
/**********************
 *  WiFi FUNCTIONS
 **********************/
// Wifi Setting pop up window
// #define LCD_WIDTH   240 //LCD width
// #define LCD_HEIGHT  320 //LCD height

static void buildSettings(void)
{
  settings = lv_obj_create(lv_scr_act());
  // lv_obj_add_style(settings, &border_style, 0);
  lv_obj_set_size(settings, 230, 280);
  lv_obj_align(settings, LV_ALIGN_TOP_RIGHT, -5, 20);

  settinglabel = lv_label_create(settings);
  lv_label_set_text(settinglabel, "Settings " LV_SYMBOL_SETTINGS);
  lv_obj_align(settinglabel, LV_ALIGN_TOP_LEFT, 0, 0);

  settingCloseBtn = lv_btn_create(settings);
  lv_obj_set_size(settingCloseBtn, 30, 30);
  lv_obj_align(settingCloseBtn, LV_ALIGN_TOP_RIGHT, 0, -10);
  lv_obj_add_event_cb(settingCloseBtn, Wifi_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_t *btnSymbol = lv_label_create(settingCloseBtn);
  lv_label_set_text(btnSymbol, LV_SYMBOL_CLOSE);
  lv_obj_center(btnSymbol);

  settingWiFiSwitch = lv_switch_create(settings);
  lv_obj_add_event_cb(settingWiFiSwitch, Wifi_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_align_to(settingWiFiSwitch, settinglabel, LV_ALIGN_TOP_RIGHT, 80, -5);
  lv_obj_add_flag(settings, LV_OBJ_FLAG_HIDDEN);

  wfList = lv_list_create(settings);
  lv_obj_set_size(wfList, 200, 240);
  lv_obj_align_to(wfList, settinglabel, LV_ALIGN_TOP_LEFT, -5, 30);
}

static void buildPWMsgBox(void)
{

  mboxConnect = lv_obj_create(lv_scr_act());
  // lv_obj_add_style(mboxConnect, &border_style, 0);
  lv_obj_set_size(mboxConnect, 230, 320 / 2);
  lv_obj_center(mboxConnect);

  mboxTitle = lv_label_create(mboxConnect);
  lv_label_set_text(mboxTitle, "WiFi SSID: ThatProject");
  lv_obj_align(mboxTitle, LV_ALIGN_TOP_LEFT, 0, 0);

  mboxPassword = lv_textarea_create(mboxConnect);
  lv_obj_set_size(mboxPassword, 200, 40);
  lv_obj_align_to(mboxPassword, mboxTitle, LV_ALIGN_TOP_LEFT, 0, 30);
  lv_textarea_set_placeholder_text(mboxPassword, "Password?");
  lv_obj_add_event_cb(mboxPassword, text_input_event_cb, LV_EVENT_ALL, keyboard);

  mboxConnectBtn = lv_btn_create(mboxConnect);
  lv_obj_add_event_cb(mboxConnectBtn, Wifi_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_align(mboxConnectBtn, LV_ALIGN_BOTTOM_LEFT, 0, 0);

  lv_obj_set_size(mboxConnectBtn, 80, 40);

  lv_obj_t *btnLabel = lv_label_create(mboxConnectBtn);
  lv_label_set_text(btnLabel, "Connect");
  lv_obj_center(btnLabel);

  mboxCloseBtn = lv_btn_create(mboxConnect);
  lv_obj_add_event_cb(mboxCloseBtn, Wifi_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_align(mboxCloseBtn, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

  lv_obj_set_size(mboxCloseBtn, 80, 40);

  lv_obj_t *btnLabel2 = lv_label_create(mboxCloseBtn);
  lv_label_set_text(btnLabel2, "Cancel");
  lv_obj_center(btnLabel2);
}

void makeKeyboard(void)
{
  keyboard = lv_keyboard_create(lv_scr_act());
  lv_obj_add_flag(keyboard, LV_OBJ_FLAG_HIDDEN);
}

///////////////////////////////////////////////////////////////

/**********************
 *  CALIBRATE FUNCTIONS
 **********************/
static void buildCalibrate(void)
{
  Calibrate = lv_obj_create(lv_scr_act());
  // lv_obj_add_style(settings, &border_style, 0);
  lv_obj_set_size(Calibrate, 230, 280);
  lv_obj_align(Calibrate, LV_ALIGN_TOP_RIGHT, -5, 20);

  lv_obj_t *Callabel = lv_label_create(Calibrate);
  lv_label_set_text(Callabel, "Calibrate " LV_SYMBOL_SETTINGS);
  lv_obj_align(Callabel, LV_ALIGN_TOP_LEFT, 0, 0);

  CalCloseBtn = lv_btn_create(Calibrate);
  lv_obj_set_size(CalCloseBtn, 30, 30);
  lv_obj_align(CalCloseBtn, LV_ALIGN_TOP_RIGHT, 0, -10);
  lv_obj_add_event_cb(CalCloseBtn, Wifi_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_t *btnSymbol2 = lv_label_create(CalCloseBtn);
  lv_label_set_text(btnSymbol2, LV_SYMBOL_CLOSE);
  lv_obj_center(btnSymbol2);

  // Create a text label in font size 32 to display the latest temperature reading
  Temp_Cal = lv_label_create(Calibrate);
  lv_label_set_text(Temp_Cal, "0.0");
  lv_obj_align(Temp_Cal, LV_ALIGN_CENTER, 0, 0);

  static lv_style_t style;
  lv_style_init(&style);
  lv_style_set_text_font(&style, &lv_font_montserrat_48); /*Set a larger font*/

  lv_obj_add_style(Temp_Cal, &style, 0);

  CalPlusBtn = lv_btn_create(Calibrate);
  lv_obj_set_size(CalPlusBtn, 30, 30);
  lv_obj_align(CalPlusBtn, LV_ALIGN_RIGHT_MID, 0, 0);
  lv_obj_add_event_cb(CalPlusBtn, Calibrate_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_t *btnSymbolP = lv_label_create(CalPlusBtn);
  lv_label_set_text(btnSymbolP, LV_SYMBOL_RIGHT);
  lv_obj_center(btnSymbolP);

  CalMinBtn = lv_btn_create(Calibrate);
  lv_obj_set_size(CalMinBtn, 30, 30);
  lv_obj_align(CalMinBtn, LV_ALIGN_LEFT_MID, 0, 0);
  lv_obj_add_event_cb(CalMinBtn, Calibrate_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_t *btnSymbolM = lv_label_create(CalMinBtn);
  lv_label_set_text(btnSymbolM, LV_SYMBOL_LEFT);
  lv_obj_center(btnSymbolM);

  // CalSaveBtn
  CalSaveBtn = lv_btn_create(Calibrate);
  lv_obj_align(CalSaveBtn, LV_ALIGN_BOTTOM_MID, 40, -10);
  lv_obj_add_event_cb(CalSaveBtn, Calibrate_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_set_height(CalSaveBtn, LV_SIZE_CONTENT);

  lv_obj_t *btn_labelS = lv_label_create(CalSaveBtn);
  lv_label_set_text(btn_labelS, "Save");
  lv_obj_center(btn_labelS);

  CalResetBtn = lv_btn_create(Calibrate);
  lv_obj_align(CalResetBtn, LV_ALIGN_BOTTOM_MID, -40, -10);
  lv_obj_add_event_cb(CalResetBtn, Calibrate_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_set_height(CalResetBtn, LV_SIZE_CONTENT);

  lv_obj_t *btn_labelR = lv_label_create(CalResetBtn);
  lv_label_set_text(btn_labelR, "Reset");
  lv_obj_center(btn_labelR);
}

static void Calibrate_btn_event_cb(lv_event_t *e)
{

  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *btn = lv_event_get_target(e);

  if (code == LV_EVENT_CLICKED)
  {
    char buf[100];
    if (btn == CalPlusBtn)
    {
      Cal_temp = Cal_temp + 0.1;
      snprintf(buf, sizeof(buf), "%.1f", Cal_temp);
      lv_label_set_text(Temp_Cal, buf);
    }
    else if (btn == CalMinBtn)
    {
      Cal_temp = Cal_temp - 0.1;
      snprintf(buf, sizeof(buf), "%.1f", Cal_temp);
      lv_label_set_text(Temp_Cal, buf);
    }
    else if (btn == CalResetBtn)
    {
      Cal_temp = 0.0;
      snprintf(buf, sizeof(buf), "%.1f", Cal_temp);
      lv_label_set_text(Temp_Cal, buf);
    }
    else if (btn == CalSaveBtn)
    {
      printf("Save calibrate config \n");

      preferences.begin("Cal_preset", false);
      preferences.putFloat("Cal1", Cal_temp);
      // Close Preferences
      preferences.end();

      lv_obj_add_flag(Calibrate, LV_OBJ_FLAG_HIDDEN);
      popupMsgBox("Save Complete", "Save calibrate config");
    }
  }
}

////// Shutdown Page ///////////////////

static void buildPower(void)
{
  Power = lv_obj_create(lv_scr_act());
  // lv_obj_add_style(settings, &border_style, 0);
  lv_obj_set_size(Power, 230, 180);
  lv_obj_align(Power, LV_ALIGN_CENTER, 0, 0);

  lv_obj_t *PWlabel = lv_label_create(Power);
  lv_label_set_text(PWlabel, "Shutdown " LV_SYMBOL_POWER);
  lv_obj_align(PWlabel, LV_ALIGN_TOP_LEFT, 0, 0);

  lv_obj_t *PWlabelC = lv_label_create(Power);
  lv_label_set_text(PWlabelC, "Do you want to shutdown device?");
  lv_obj_align(PWlabelC, LV_ALIGN_CENTER, 0, 0);

  PWCloseBtn = lv_btn_create(Power);
  lv_obj_set_size(PWCloseBtn, 30, 30);
  lv_obj_align(PWCloseBtn, LV_ALIGN_TOP_RIGHT, 0, -10);
  lv_obj_add_event_cb(PWCloseBtn, Wifi_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_t *btnSymbolCP = lv_label_create(PWCloseBtn);
  lv_label_set_text(btnSymbolCP, LV_SYMBOL_CLOSE);
  lv_obj_center(btnSymbolCP);

  ShutdownBtn = lv_btn_create(Power);
  lv_obj_set_size(ShutdownBtn, 70, 30);
  lv_obj_align(ShutdownBtn, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
  lv_obj_add_event_cb(ShutdownBtn, Wifi_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_t *btnSymbolPB = lv_label_create(ShutdownBtn);
  lv_label_set_text(btnSymbolPB, "Shutdown");
  lv_obj_center(btnSymbolPB);

  ShutdownCanBtn = lv_btn_create(Power);
  lv_obj_set_size(ShutdownCanBtn, 70, 30);
  lv_obj_align(ShutdownCanBtn, LV_ALIGN_BOTTOM_LEFT, 0, 0);
  lv_obj_add_event_cb(ShutdownCanBtn, Wifi_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_t *btnPCB = lv_label_create(ShutdownCanBtn);
  lv_label_set_text(btnPCB, "Cancel");
  lv_obj_center(btnPCB);
}

///////////////////////////////////////////////////////////////
static void networkScanner()
{
  xTaskCreate(scanWIFITask,
              "ScanWIFITask",
              4096,
              NULL,
              1,
              &ntScanTaskHandler);
}

static void scanWIFITask(void *pvParameters)
{
  while (1)
  {
    foundWifiList.clear();
    int n = WiFi.scanNetworks();
    vTaskDelay(10);
    for (int i = 0; i < n; ++i)
    {
      String item = WiFi.SSID(i) + " (" + WiFi.RSSI(i) + ") " + ((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      foundWifiList.push_back(item);
      vTaskDelay(10);
    }
    vTaskDelay(5000);
  }
}

static void showingFoundWiFiList(void)
{
  if (foundWifiList.size() == 0 || foundNetworks == foundWifiList.size())
    return;

  lv_obj_clean(wfList);
  lv_list_add_text(wfList, foundWifiList.size() > 1 ? "WiFi: Found Networks" : "WiFi: Not Found!");

  for (std::vector<String>::iterator item = foundWifiList.begin(); item != foundWifiList.end(); ++item)
  {
    lv_obj_t *btn = lv_list_add_btn(wfList, LV_SYMBOL_WIFI, (*item).c_str());
    lv_obj_add_event_cb(btn, list_event_handler, LV_EVENT_CLICKED, NULL);
    delay(1);
  }

  foundNetworks = foundWifiList.size();
}

static void timerForNetwork(lv_timer_t *timer)
{
  LV_UNUSED(timer);

  switch (networkStatus)
  {

  case NETWORK_SEARCHING:
    showingFoundWiFiList();
    break;

  case NETWORK_CONNECTED_POPUP:
    popupMsgBox("WiFi Connected!", "Now you'll get the current time soon.");
    networkStatus = NETWORK_CONNECTED;
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    lv_obj_move_background(popupBox);

    break;

  case NETWORK_CONNECTED:

    showingFoundWiFiList();
    updateLocalTime();

    // lv_obj_move_background(mboxConnect);
    lv_label_set_text(Wifi_label, "WiFi Connected.");

    break;

  case NETWORK_CONNECT_FAILED:
    networkStatus = NETWORK_SEARCHING;
    popupMsgBox("Oops!", "Please check your wifi password and try again.");

    lv_label_set_text(Wifi_label, "WiFi Disconnected.");

    break;

  default:
    break;
  }
}

static void Wifi_btn_event_cb(lv_event_t *e)
{

  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *btn = lv_event_get_target(e);

  if (code == LV_EVENT_CLICKED)
  {
    if (btn == settingBtn)
    {
      lv_obj_clear_flag(settings, LV_OBJ_FLAG_HIDDEN);
    }
    else if (btn == settingCloseBtn)
    {
      lv_obj_add_flag(settings, LV_OBJ_FLAG_HIDDEN);
    }
    else if (btn == mboxConnectBtn)
    {
      // ssidPW = String(lv_textarea_get_text(mboxPassword));
      ssidPW = "hahahahahamama";
      printf("SSID: %s \n", ssidName);
      printf("Password: %s \n", ssidPW);

      networkConnector();
      lv_obj_move_background(mboxConnect);
      popupMsgBox("Connecting!", "Attempting to connect to the selected network.");
    }
    else if (btn == mboxCloseBtn)
    {
      lv_obj_move_background(mboxConnect);
    }
    else if (btn == popupBoxCloseBtn)
    {
      // lv_textarea_clear_selection(mboxPassword);
      lv_textarea_set_text(mboxPassword, "");
      lv_obj_move_background(popupBox);
    }

    else if (btn == Del_popupBoxCloseBtn)
    {
      // lv_textarea_clear_selection(mboxPassword);
      lv_obj_move_background(Del_popupBox);
    }

    else if (btn == Del_Btn)
    {
      printf(Hold_filename.c_str());
      if (SD_MMC.remove(Hold_filename.c_str()))
      {
        printf("File deleted successfully.");

        foundFileList.clear();

        LVGL_Search_SD();

        lv_obj_clean(sdList);

        for (std::vector<String>::iterator item = foundFileList.begin(); item != foundFileList.end(); ++item)
        {
          lv_obj_t *btn = lv_list_add_btn(sdList, LV_SYMBOL_FILE, (*item).c_str());
          // lv_obj_add_event_cb(btn,Filelist_event_handler, LV_EVENT_CLICKED, NULL);
          lv_obj_add_event_cb(btn, Filelist_event_handler, LV_EVENT_ALL, NULL);
        }
      }
      else
      {
        printf("Failed to delete file.");
      }

      lv_obj_move_background(Del_popupBox);
    }

    ///// Calibrate //////

    else if (btn == CalBtn)
    {
      lv_obj_clear_flag(Calibrate, LV_OBJ_FLAG_HIDDEN);
    }
    else if (btn == CalCloseBtn)
    {
      lv_obj_add_flag(Calibrate, LV_OBJ_FLAG_HIDDEN);
    }

    else if (btn == PWBtn)
    {
      lv_obj_clear_flag(Power, LV_OBJ_FLAG_HIDDEN);
    }
    else if (btn == ShutdownBtn)
    {
      printf("Deep Sleep \n");
      esp_deep_sleep_start();
    }
    else if (btn == PWCloseBtn)
    {
      lv_obj_add_flag(Power, LV_OBJ_FLAG_HIDDEN);
    }
    else if (btn == ShutdownCanBtn)
    {
      lv_obj_add_flag(Power, LV_OBJ_FLAG_HIDDEN);
    }
  }
  else if (code == LV_EVENT_VALUE_CHANGED)
  {
    if (btn == settingWiFiSwitch)
    {

      if (lv_obj_has_state(btn, LV_STATE_CHECKED))
      {

        if (ntScanTaskHandler == NULL)
        {
          networkStatus = NETWORK_SEARCHING;
          networkScanner();
          timer = lv_timer_create(timerForNetwork, 1000, wfList);
          lv_list_add_text(wfList, "WiFi: Looking for Networks...");
        }
      }
      else
      {

        if (ntScanTaskHandler != NULL)
        {
          networkStatus = NONE;
          vTaskDelete(ntScanTaskHandler);
          ntScanTaskHandler = NULL;
          lv_timer_del(timer);
          lv_obj_clean(wfList);
        }

        if (WiFi.status() == WL_CONNECTED)
        {
          WiFi.disconnect(true);
          // lv_label_set_text(RTC_Time, "WiFi Not Connected!    " LV_SYMBOL_CLOSE);
          lv_textarea_set_placeholder_text(RTC_Time, "WiFi Not Connected!    " LV_SYMBOL_CLOSE);
          // Time_label
          lv_label_set_text(Wifi_label, "WiFi not Connected.");

          date_time = "WiFi not Connect";
          FN_date_time = "/Wifi_not_Connected.txt";
        }
      }
    }
  }
}

static void list_event_handler(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *obj = lv_event_get_target(e);

  if (code == LV_EVENT_CLICKED)
  {

    String selectedItem = String(lv_list_get_btn_text(wfList, obj));
    for (int i = 0; i < selectedItem.length() - 1; i++)
    {
      if (selectedItem.substring(i, i + 2) == " (")
      {
        ssidName = selectedItem.substring(0, i);
        lv_label_set_text_fmt(mboxTitle, "WiFi SSID: %s", ssidName);
        lv_obj_move_foreground(mboxConnect);
        break;
      }
    }
  }
}

void beginWIFITask(void *pvParameters)
{

  printf("Begin WiFi Task...\n");

  unsigned long startingTime = millis();
  WiFi.mode(WIFI_STA);
  // WiFi.disconnect();
  vTaskDelay(100);

  WiFi.begin(ssidName.c_str(), ssidPW.c_str());
  while (WiFi.status() != WL_CONNECTED && (millis() - startingTime) < networkTimeout)
  {
    vTaskDelay(250);
  }

  if (WiFi.status() == WL_CONNECTED)
  {
    networkStatus = NETWORK_CONNECTED_POPUP;
    // saveWIFICredentialEEPROM(1, ssidName + " " + ssidPW);
  }
  else
  {
    networkStatus = NETWORK_CONNECT_FAILED;
    // saveWIFICredentialEEPROM(0, "");
  }
  vTaskDelete(NULL);
}

static void text_input_event_cb(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *ta = lv_event_get_target(e);

  if (code == LV_EVENT_FOCUSED)
  {
    lv_obj_move_foreground(keyboard);
    lv_keyboard_set_textarea(keyboard, ta);
    lv_obj_clear_flag(keyboard, LV_OBJ_FLAG_HIDDEN);
  }

  if (code == LV_EVENT_DEFOCUSED)
  {
    lv_keyboard_set_textarea(keyboard, NULL);
    lv_obj_add_flag(keyboard, LV_OBJ_FLAG_HIDDEN);
  }
}

static void popupMsgBox(String title, String msg)
{

  // #define LCD_WIDTH   240 //LCD width
  // #define LCD_HEIGHT  320 //LCD height

  if (popupBox != NULL)
  {
    lv_obj_del(popupBox);
  }

  popupBox = lv_obj_create(lv_scr_act());
  // lv_obj_add_style(popupBox, &popupBox_style, 0);
  lv_obj_set_size(popupBox, 240 * 2 / 3, 320 / 2);
  lv_obj_center(popupBox);

  lv_obj_t *popupTitle = lv_label_create(popupBox);
  lv_label_set_text(popupTitle, title.c_str());
  lv_obj_set_width(popupTitle, 240 * 2 / 3 - 50);
  lv_obj_align(popupTitle, LV_ALIGN_TOP_LEFT, 0, 0);

  lv_obj_t *popupMSG = lv_label_create(popupBox);
  lv_obj_set_width(popupMSG, 240 * 2 / 3 - 50);
  lv_label_set_text(popupMSG, msg.c_str());
  lv_obj_align(popupMSG, LV_ALIGN_TOP_LEFT, 0, 40);

  popupBoxCloseBtn = lv_btn_create(popupBox);
  lv_obj_add_event_cb(popupBoxCloseBtn, Wifi_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_align(popupBoxCloseBtn, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
  lv_obj_t *btnLabel = lv_label_create(popupBoxCloseBtn);
  lv_label_set_text(btnLabel, "Close");
  lv_obj_center(btnLabel);
}

void updateLocalTime(void)
{

  // printf("Get local time... \n");

  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    printf("Failed to obtain time \n");

    return;
  }

  rawtime = mktime(&timeinfo);

  char timeStr[50];
  strftime(timeStr, sizeof(timeStr), "%d %m %Y , %H:%M:%S", &timeinfo);

  date_time = String(timeStr);

  lv_textarea_set_placeholder_text(RTC_Time, timeStr);

  strftime(timeStr, sizeof(timeStr), "/%d_%m_%Y.txt", &timeinfo);
  FN_date_time = String(timeStr);
}

/**********************
 *   READ TEMP FUNCTIONS
 **********************/

static void Temp_create(lv_obj_t *parent)
{
  arc = lv_arc_create(parent);
  lv_obj_set_size(arc, 210, 210);
  lv_arc_set_rotation(arc, 135);
  lv_arc_set_bg_angles(arc, 0, 270);
  lv_arc_set_range(arc, 0, 100);
  lv_obj_align(arc, LV_ALIGN_CENTER, 0, 10);
  lv_arc_set_value(arc, 0);
  lv_obj_remove_style(arc, NULL, LV_PART_KNOB);
  lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE);

  // Create a text label in font size 32 to display the latest temperature reading
  Temp_CC = lv_label_create(parent);
  lv_label_set_text(Temp_CC, "--.--");
  lv_obj_align(Temp_CC, LV_ALIGN_CENTER, 0, 10);

  static lv_style_t style;
  lv_style_init(&style);
  lv_style_set_text_font(&style, &lv_font_montserrat_48); /*Set a larger font*/

  lv_obj_add_style(Temp_CC, &style, 0);

  // create spiner//
  spinner = lv_spinner_create(parent, 3000, 80);
  lv_obj_align(spinner, LV_ALIGN_CENTER, 0, -45);
  lv_obj_set_size(spinner, 40, 40);
  lv_obj_add_flag(spinner, LV_OBJ_FLAG_HIDDEN);

  // Create a Toggle button (btn2)
  Start_btn = lv_btn_create(parent);
  lv_obj_add_event_cb(Start_btn, event_handler_Start_btn, LV_EVENT_CLICKED, NULL);
  lv_obj_align(Start_btn, LV_ALIGN_CENTER, 0, 60);
  lv_obj_add_flag(Start_btn, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_set_height(Start_btn, LV_SIZE_CONTENT);

  btn_label = lv_label_create(Start_btn);
  lv_label_set_text(btn_label, "Start");
  lv_obj_center(btn_label);

  //////////////////////////////////////////////

  Wifi_label = lv_label_create(parent);
  lv_label_set_text(Wifi_label, "WiFi not Connected.");
  // lv_obj_align(Wifi_label , LV_ALIGN_TOP_MID, 0, 10);
  lv_obj_align(Wifi_label, LV_ALIGN_BOTTOM_MID, 0, -10);

  /////////////////////////////////////////////////////
  SKU_label = lv_label_create(parent);
  lv_label_set_text(SKU_label, "Unknown SKU.");
  lv_obj_align(SKU_label, LV_ALIGN_TOP_MID, 0, 10);
  // lv_obj_align(Wifi_label , LV_ALIGN_BOTTOM_MID, 0, -10);

  Bat_bar = lv_bar_create(parent);
  lv_obj_set_size(Bat_bar, 50, 20);
  lv_obj_align(Bat_bar, LV_ALIGN_TOP_LEFT, 0, 5);
  // lv_bar_set_anim_time(Bat_bar, 2000);
  lv_bar_set_value(Bat_bar, 0, LV_ANIM_ON);

  Bat_text = lv_label_create(parent);
  lv_label_set_text(Bat_text, "0");
  lv_obj_align(Bat_text, LV_ALIGN_TOP_LEFT, 12, 8);

  // Initialize all readings to 0
  for (int i = 0; i < numReadings; i++)
  {
    B_readings[i] = 0;
  }

  ////////////////////////////////////////////////////

  settingBtn = lv_btn_create(parent);
  lv_obj_set_size(settingBtn, 40, 40);
  lv_obj_align(settingBtn, LV_ALIGN_TOP_RIGHT, 0, 0);

  lv_obj_add_event_cb(settingBtn, Wifi_btn_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_t *label = lv_label_create(settingBtn); /*Add a label to the button*/
  // lv_obj_add_style(label, &style, 0);
  lv_label_set_text(label, LV_SYMBOL_WIFI); /*Set the labels text*/
  lv_obj_center(label);

  CalBtn = lv_btn_create(parent);
  lv_obj_set_size(CalBtn, 35, 35);
  lv_obj_align(CalBtn, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
  lv_obj_t *Cal_label = lv_label_create(CalBtn);    /*Add a label to the button*/
  lv_label_set_text(Cal_label, LV_SYMBOL_SETTINGS); /*Set the labels text*/
  lv_obj_center(Cal_label);
  lv_obj_add_event_cb(CalBtn, Wifi_btn_event_cb, LV_EVENT_ALL, NULL);

  PWBtn = lv_btn_create(parent);
  lv_obj_set_size(PWBtn, 35, 35);
  lv_obj_align(PWBtn, LV_ALIGN_BOTTOM_LEFT, 0, 0);
  lv_obj_t *PW_label = lv_label_create(PWBtn);  /*Add a label to the button*/
  lv_label_set_text(PW_label, LV_SYMBOL_POWER); /*Set the labels text*/
  lv_obj_center(PW_label);
  lv_obj_add_event_cb(PWBtn, Wifi_btn_event_cb, LV_EVENT_ALL, NULL);

  buildPWMsgBox();
  buildSettings();
  buildCalibrate();
  buildPower();

  makeKeyboard();

  lv_obj_add_flag(Calibrate, LV_OBJ_FLAG_HIDDEN);
  lv_obj_add_flag(Power, LV_OBJ_FLAG_HIDDEN);
  lv_obj_move_background(mboxConnect);

  // Initialize Preferences with namespace "my-app"
  preferences.begin("Cal_preset", true);

  if (preferences.isKey("Cal1"))
  {
    printf("Found save data");

    // Read the float data if the key exists
    float readFloat = preferences.getFloat("Cal1");
    Cal_temp = readFloat;

    char tem[100];
    snprintf(tem, sizeof(tem), "%.1f", Cal_temp);
    lv_label_set_text(Temp_Cal, tem);

    printf("Load Calibrate: %.1f \n", Cal_temp);
  }
  else
  {
    printf("No Calibrate data.");
    Cal_temp = 0.0;
  }

  preferences.end();

  lv_obj_add_state(settingWiFiSwitch, LV_STATE_CHECKED);
  lv_event_send(settingWiFiSwitch, LV_EVENT_VALUE_CHANGED, NULL);

  auto_temp_timer = lv_timer_create(Temp_Read, 200, NULL);
  timeout_timer = lv_timer_create(screen_timeout, 60000, NULL);

  sleep_timer = lv_timer_create(sleep_mode, 3600000, NULL);
  // sleep_timer = lv_timer_create(sleep_mode,60000, NULL);
}

/**********************
 *   API & MQTT TESTING FUNCTIONS
 **********************/
lv_obj_t *responseLabel;
lv_obj_t *dropdownSKU;
lv_obj_t *BatchNo;
char SKUs[50][50];
char SKUs_nonDup[50][50];
lv_style_t my_style;
int SKUcounter = 0;
int SKUnonDupCount = 0;
int selectedBatchNo = 0;

static void API_tester_create(lv_obj_t *parent)
{
  // API testing button
  APIBtn = lv_btn_create(parent);
  lv_obj_set_size(APIBtn, 35, 50);
  lv_obj_align(APIBtn, LV_ALIGN_CENTER, 0, 0);
  lv_obj_t *API_label = lv_label_create(APIBtn); /*Add a label to the button*/
  lv_label_set_text(API_label, LV_SYMBOL_POWER); /*Set the labels text*/
  lv_obj_center(API_label);
  lv_obj_add_event_cb(APIBtn, API_btn_event_cb, LV_EVENT_ALL, NULL);

  // API testing button
  APISendBtn = lv_btn_create(parent);
  lv_obj_set_size(APISendBtn, 35, 50);
  lv_obj_align(APISendBtn, LV_ALIGN_CENTER, 0, -20);
  lv_obj_t *APISend_label = lv_label_create(APISendBtn); /*Add a label to the button*/
  lv_label_set_text(APISend_label, LV_SYMBOL_CHARGE); /*Set the labels text*/
  lv_obj_center(APISend_label);
  lv_obj_add_event_cb(APISendBtn, API_btn_event_cb, LV_EVENT_ALL, NULL);

  // SKU dropdown
  dropdownSKU = lv_dropdown_create(parent);
  lv_obj_align(dropdownSKU, LV_ALIGN_CENTER, 0, 40);
  lv_dropdown_set_options(dropdownSKU, "");
  lv_obj_set_style_text_font(dropdownSKU, &Sarabun, LV_PART_MAIN);
  /*Use a custom image as down icon and flip it when the list is opened*/
  LV_IMG_DECLARE(img_caret_down)
  lv_dropdown_set_symbol(dropdownSKU, &img_caret_down);
  lv_obj_add_event_cb(dropdownSKU, SKU_dropdown_event_cb, LV_EVENT_ALL, NULL);
  // set Thai font style to dropdown list items
  lv_obj_t *list = lv_dropdown_get_list(dropdownSKU); // get list object
  lv_style_init(&my_style);                           // Initialize the style
  lv_style_set_text_font(&my_style, &Sarabun);        // Set the font
  lv_obj_add_style(list, &my_style, LV_PART_MAIN);    // Apply the style to the list object

  // Batch Number placeholder
  BatchNo = lv_label_create(parent);
  lv_obj_set_width(BatchNo, 100);
  lv_label_set_text_fmt(BatchNo, "Batch no. : %d", selectedBatchNo + 1);
  lv_obj_align(BatchNo, LV_ALIGN_CENTER, 0, 80);

  // Batch selection
  BatchUpBtn = lv_btn_create(parent);
  lv_obj_set_size(BatchUpBtn, 35, 50);
  lv_obj_align(BatchUpBtn, LV_ALIGN_CENTER, 60, 80);
  lv_obj_t *BatchUp_label = lv_label_create(BatchUpBtn); /*Add a label to the button*/
  lv_label_set_text(BatchUp_label, LV_SYMBOL_PLUS);      /*Set the labels text*/
  lv_obj_center(BatchUp_label);
  lv_obj_add_event_cb(BatchUpBtn, batch_change_event_cb, LV_EVENT_ALL, NULL);

  BatchDownBtn = lv_btn_create(parent);
  lv_obj_set_size(BatchDownBtn, 35, 50);
  lv_obj_align(BatchDownBtn, LV_ALIGN_CENTER, -60, 80);
  lv_obj_t *BatchDown_label = lv_label_create(BatchDownBtn); /*Add a label to the button*/
  lv_label_set_text(BatchDown_label, LV_SYMBOL_MINUS);       /*Set the labels text*/
  lv_obj_center(BatchDown_label);
  lv_obj_add_event_cb(BatchDownBtn, batch_change_event_cb, LV_EVENT_ALL, NULL);
}

static void batch_change_event_cb(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *btn = lv_event_get_target(e);
  if (code == LV_EVENT_CLICKED)
  {
    if (btn == BatchUpBtn)
    {
      selectedBatchNo++;
      lv_label_set_text_fmt(BatchNo, "Batch no. : %d", selectedBatchNo + 1);
      lv_dropdown_set_text(dropdownSKU, SKUs[selectedBatchNo]);
      printf("batch no : %d, sku : %s\n", selectedBatchNo, SKUs[selectedBatchNo]);
    }
    else if (btn == BatchDownBtn)
    {
      selectedBatchNo--;
      if(selectedBatchNo < 0) {
        selectedBatchNo = 0;
      }
      lv_label_set_text_fmt(BatchNo, "Batch no. : %d", selectedBatchNo + 1);
      lv_dropdown_set_text(dropdownSKU, SKUs[selectedBatchNo]);
      printf("batch no : %d, sku : %s\n", selectedBatchNo, SKUs[selectedBatchNo]);
    }
  }
}

static void SKU_dropdown_event_cb(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *obj = lv_event_get_target(e);
  if (code == LV_EVENT_VALUE_CHANGED)
  {
    lv_dropdown_set_text(dropdownSKU, NULL);
    int id = lv_dropdown_get_selected(dropdownSKU);
    lv_dropdown_set_selected(dropdownSKU, id);
  }
}

static void API_btn_event_cb(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *btn = lv_event_get_target(e);
  if (code == LV_EVENT_CLICKED)
  {
    if (btn == APIBtn)
    {
      getSKUFromAPI();
    }
  }
}

static void getSKUFromAPI()
{
  clearSKUlist(); // reset SKU dropdown and arrays
  printf("___________________________________");
  String serverName = "https://4670c375-148f-45e6-9f59-78fe1fa3f94b.mock.pstmn.io/getSKU";
  String payload;
  unsigned long lastTime = 0;
  unsigned long timerDelay = 5000;

  WiFiClientSecure *client = new WiFiClientSecure;

  HTTPClient http;
  http.begin(serverName.c_str());
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0)
  {
    payload = http.getString();
  }
  else
  {
    printf("API testing failed with code : %d", httpResponseCode);
    return;
  }
  http.end();

  JsonDocument SKUjson;
  DeserializationError error = deserializeJson(SKUjson, payload.c_str());
  if (error)
  {
    printf("deserializeJson() failed: %s", error.c_str());
    return;
  }

  JsonObject SKUlist = SKUjson["BAKERY_BATCH_DATA"][0];

  bool isFirst = 0;
  String new_menu = "";
  String new_menu_deduplicated = "";
  for (JsonPair SKU : SKUlist)
  {
    // key = batchno ; don't use this btw
    // value = SKU ;in format of -> no, SKU name, bool

    // printf(kv.key().c_str());
    // printf(kv.value().as<const char*>());
    String temp = SKU.value().as<String>();
    int firstComma = temp.indexOf(',');
    int secondComma = temp.indexOf(',', firstComma + 1);
    new_menu += temp.substring(firstComma + 2, secondComma).c_str();
    strcpy(SKUs[SKUcounter], temp.substring(firstComma + 2, secondComma).c_str());
    addSKUnonDup(temp.substring(firstComma + 2, secondComma).c_str());
    SKUcounter++;
    if (isFirst)
    {
      isFirst = false;
    }
    else
    {
      new_menu += "\n";
    }
  }

  addSKUList();

  // lv_dropdown_set_options(dropdownSKU, new_menu.c_str());
  // lv_obj_set_style_text_font(dropdownSKU, &Sarabun, LV_PART_MAIN);

  // printf(new_menu.c_str());
  /*printf("SKU list:\n");
  for (int i = 0; i < SKUnonDupCount; i++)
  {
    printf("%d %s\n", i, SKUs_nonDup[i]);
  }*/

  //http.end();
}

static void addSKUnonDup(const char *item)
{
  String temp = SKUs_nonDup[SKUnonDupCount];
  if (SKUnonDupCount == 0)
  {
    strcpy(SKUs_nonDup[SKUnonDupCount], item);
    SKUnonDupCount++;
  }
  else if (strcmp(SKUs_nonDup[SKUnonDupCount - 1], item) != 0)
  {
    // printf("%s compare with %s\n", SKUs_nonDup[SKUnonDupCount-1], item);
    strcpy(SKUs_nonDup[SKUnonDupCount], item);
    SKUnonDupCount++;
  }
}

static void addSKUList()
{
  String temp = "";
  for (int i = 0; i < SKUnonDupCount; i++)
  {
    temp += SKUs_nonDup[i];
    if (i + 1 < SKUnonDupCount)
    {
      temp += "\n";
    }
  }
  lv_dropdown_set_options(dropdownSKU, temp.c_str());
  lv_obj_set_style_text_font(dropdownSKU, &Sarabun, LV_PART_MAIN);
}

static void clearSKUlist()
{
  for (int i = 0; i < SKUnonDupCount; i++)
  {
    strcpy(SKUs_nonDup[SKUnonDupCount], "");
  }
  SKUnonDupCount = 0;

  for (int i = 0; i < SKUcounter; i++)
  {
    strcpy(SKUs[SKUcounter], "");
  }
  SKUcounter = 0;

  lv_dropdown_set_text(dropdownSKU, NULL);
  lv_dropdown_set_options(dropdownSKU, "");
}

///////////////// Screen timeout ////////////////////////////////

void IRAM_ATTR sleep_mode(lv_timer_t *t)
{
  printf("Deep Sleep \n");
  esp_deep_sleep_start();
}

void IRAM_ATTR screen_timeout(lv_timer_t *t)
{
  // lv_scr_load(screen_off);
  // LCD_Backlight_PIN
  // digitalWrite(LCD_Backlight_PIN, LOW);
  LCD_Backlight = 0;
  Set_Backlight(0);
  // LVGL_Backlight_adjustment
  printf("Turn off screen \n");
}

void reset_screen_timeout(void)
{
  lv_timer_reset(timeout_timer);
  lv_timer_reset(sleep_timer);
}
/////////////////////////////////////////////////////////////

void IRAM_ATTR Temp_Read(lv_timer_t *t)
{
  char buf[100];

  if (WiFi.status() != WL_CONNECTED)
  {
    lv_label_set_text(Wifi_label, "WiFi Disconnected.");
  }

  if (Touch_interrupts)
  {
    printf("Touch: %u \n", Touch_interrupts);
    // digitalWrite(LCD_Backlight_PIN,LCD_Backlight);
    LCD_Backlight = BU_LCD_Backlight;
    Set_Backlight(LCD_Backlight);
    reset_screen_timeout();
  }

  /////Read BAT //////

  total = total - B_readings[readIndex];
  B_readings[readIndex] = BAT_percent;

  total = total + B_readings[readIndex];
  readIndex = readIndex + 1;

  // If we're at the end of the array, wrap around to the beginning
  if (readIndex >= numReadings)
  {
    readIndex = 0;
  }

  C_BAT_percent = int(total / numReadings);
  C_BAT_percent = constrain(C_BAT_percent, 0, 100);

  snprintf(buf, sizeof(buf), "%d %", C_BAT_percent);

  lv_label_set_text(Bat_text, buf);
  lv_bar_set_value(Bat_bar, C_BAT_percent, LV_ANIM_ON);
  lv_refr_now(NULL);

  ///////////////////

  if (!stop_reading)
  {

    maxthermo.triggerOneShot();
    reset_screen_timeout();
    delay(500);
    Temp_C = (float)(maxthermo.readThermocoupleTemperature());
    Temp_C = Temp_C + Cal_temp;

    lv_arc_set_value(arc, (int)Temp_C);
    lv_label_set_text(btn_label, "Stop");

    if (abs(Temp_C - previous_temp) <= temp_threshold)
    {
      stableCount++; // Increment stable count if value is within threshold
      // printf("Count \n");
    }

    else
    {
      stableCount = 0; // Reset stable count if value changes significantly
    }

    if (stableCount >= stableReadings)
    {
      previous_temp = Temp_C; // Store the stable value
      printf("Stable \n");
      printf(FN_date_time.c_str());
      printf("\n");

      lv_obj_clear_state(Start_btn, LV_STATE_CHECKED);
      lv_label_set_text(btn_label, "Start");

      snprintf(buf, sizeof(buf), "%.1f °C", Temp_C);
      lv_label_set_text(Temp_CC, buf);
      lv_arc_set_value(arc, (int)Temp_C);

      stableCount = 0;

      stable_check = true;
      stable_temp = Temp_C;

      stop_reading = true;

      /////// Save Stable Temp ///////

      StaticJsonDocument<200> JsonDoc;

      char AdString[350];
      char prod_name[50];
      lv_dropdown_get_selected_str(dropdownSKU, prod_name, 0);

      // Json format
      JsonDoc.clear();
      JsonDoc["timestamp"] = int(rawtime);
      JsonDoc["country"] = "thailand";
      JsonDoc["plant"] = "bakery";
      JsonDoc["plant_id"] = "4105";
      JsonDoc["factory"] = "xxxxxxxxxxxxx";
      JsonDoc["machine_type"] = "handheld_temp";
      JsonDoc["machine_name"] = "aft_proof_sensor";
      JsonDoc["area"] = "preparation room";
      JsonDoc["line"] = "";
      JsonDoc["product_name"] = prod_name;
      JsonDoc["shift"] = "";
      JsonDoc["batch_no"] = serialized(String(selectedBatchNo));
      JsonDoc["temp"] = serialized(String(stable_temp, 1));
      serializeJson(JsonDoc, AdString);

      printf(AdString);
      printf("\n");

      // JsonDoc.printTo(AdString, sizeof(AdString));

      if (WiFi.status() == WL_CONNECTED)
      {
        // connectAWS_B();
        connectAWS();

        printf("Publish to %s \n", AWS_IOT_PUBLISH_TOPIC);

        printf(AdString);
        printf("\n");

        bool success = client.publish(AWS_IOT_PUBLISH_TOPIC, AdString, strlen(AdString));

        if (success)
        {
          printf("Message published successfully \n");
        }
        else
        {
          printf("Message publish failed \n");
        }

        client.disconnect();
        client.loop();
      }

      // client.publish(topic_out, AdString); //
      // Serial.print("Temperature sent.");
      lv_obj_add_flag(spinner, LV_OBJ_FLAG_HIDDEN);
      if (File_CNT)
      {

        if (SD_MMC.exists(FN_date_time))
        {
          printf("File exists. \n");

          // Open file for appending
          File file = SD_MMC.open(FN_date_time, FILE_APPEND);
          if (!file)
          {
            printf("Failed to open file for appending \n");
            return;
          }

          // Append to file
          file.println(AdString);
          file.close();
        }

        else
        {
          File file = SD_MMC.open(FN_date_time, FILE_WRITE);

          if (!file)
          {
            printf("Failed to open file for writing \n");
            return;
          }

          // Write to file
          file.println(AdString);
          file.close();
          printf("File written successfully \n");

          foundFileList.clear();
          LVGL_Search_SD();
          lv_obj_clean(sdList);
          printf("Clean List \n");

          for (std::vector<String>::iterator item = foundFileList.begin(); item != foundFileList.end(); ++item)
          {
            lv_obj_t *btn = lv_list_add_btn(sdList, LV_SYMBOL_FILE, (*item).c_str());
            // lv_obj_add_event_cb(btn,Filelist_event_handler, LV_EVENT_CLICKED, NULL);
            lv_obj_add_event_cb(btn, Filelist_event_handler, LV_EVENT_ALL, NULL);
            // lv_obj_set_event_cb(btn,Filelist_event_handler);
          }
        }
      }

      ////////////////////////////////
    }

    else
    {
      previous_temp = Temp_C;

      snprintf(buf, sizeof(buf), "%.1f °C", Temp_C);
      printf("Temperature: %.1f °C \n", Temp_C);

      lv_label_set_text(Temp_CC, buf);
      lv_arc_set_value(arc, (int)Temp_C);
    }

    lv_refr_now(NULL);
    delay(500); // Wait for 1 second before taking the next reading
  }

  else if (!stable_check && stop_reading)
  {
    lv_label_set_text(Temp_CC, "--.--");
    lv_arc_set_value(arc, 0);
    lv_obj_clear_state(Start_btn, LV_STATE_CHECKED);
    lv_label_set_text(btn_label, "Start");

    stableCount = 0;
  }

  else
  {
    lv_obj_clear_state(Start_btn, LV_STATE_CHECKED);
    lv_label_set_text(btn_label, "Start");

    snprintf(buf, sizeof(buf), "%.1f °C", stable_temp);
    lv_label_set_text(Temp_CC, buf);
    lv_arc_set_value(arc, (int)stable_temp);

    stableCount = 0;
  }
}

static void event_handler_Start_btn(lv_event_t *e)
{
  if (lv_obj_has_state(Start_btn, LV_STATE_CHECKED))
  { // Button is in "On" state
    printf("Button is On\n");
    stop_reading = false;
    lv_obj_clear_flag(spinner, LV_OBJ_FLAG_HIDDEN);
  }

  else
  {
    printf("Button is Off\n");
    stop_reading = true;
    lv_obj_add_flag(spinner, LV_OBJ_FLAG_HIDDEN);
  }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void Onboard_create(lv_obj_t *parent)
{

  /*Create a panel*/
  lv_obj_t *panel1 = lv_obj_create(parent);
  lv_obj_set_height(panel1, LV_SIZE_CONTENT);

  lv_obj_t *panel1_title = lv_label_create(panel1);
  lv_label_set_text(panel1_title, "Onboard parameter");
  lv_obj_add_style(panel1_title, &style_title, 0);

  lv_obj_t *SD_label = lv_label_create(panel1);
  lv_label_set_text(SD_label, "SD Card");
  lv_obj_add_style(SD_label, &style_text_muted, 0);

  SD_Size = lv_textarea_create(panel1);
  lv_textarea_set_one_line(SD_Size, true);
  lv_textarea_set_placeholder_text(SD_Size, "SD Size");
  lv_obj_add_event_cb(SD_Size, ta_event_cb, LV_EVENT_ALL, NULL);

  lv_obj_t *Flash_label = lv_label_create(panel1);
  lv_label_set_text(Flash_label, "Flash Size");
  lv_obj_add_style(Flash_label, &style_text_muted, 0);

  FlashSize = lv_textarea_create(panel1);
  lv_textarea_set_one_line(FlashSize, true);
  lv_textarea_set_placeholder_text(FlashSize, "Flash Size");
  lv_obj_add_event_cb(FlashSize, ta_event_cb, LV_EVENT_ALL, NULL);

  lv_obj_t *BAT_label = lv_label_create(panel1);
  lv_label_set_text(BAT_label, "Battery Voltage");
  lv_obj_add_style(BAT_label, &style_text_muted, 0);

  BAT_Volts = lv_textarea_create(panel1);
  lv_textarea_set_one_line(BAT_Volts, true);
  lv_textarea_set_placeholder_text(BAT_Volts, "BAT Volts");
  lv_obj_add_event_cb(BAT_Volts, ta_event_cb, LV_EVENT_ALL, NULL);

  lv_obj_t *angle_label = lv_label_create(panel1);
  lv_label_set_text(angle_label, "Angular deflection");
  lv_obj_add_style(angle_label, &style_text_muted, 0);

  Board_angle = lv_textarea_create(panel1);
  lv_textarea_set_one_line(Board_angle, true);
  lv_textarea_set_placeholder_text(Board_angle, "Board angle");
  lv_obj_add_event_cb(Board_angle, ta_event_cb, LV_EVENT_ALL, NULL);

  lv_obj_t *Time_label = lv_label_create(panel1);
  lv_label_set_text(Time_label, "RTC Time");
  lv_obj_add_style(Time_label, &style_text_muted, 0);

  RTC_Time = lv_textarea_create(panel1);
  lv_textarea_set_one_line(RTC_Time, true);
  lv_textarea_set_placeholder_text(RTC_Time, "Display time");
  lv_obj_add_event_cb(RTC_Time, ta_event_cb, LV_EVENT_ALL, NULL);

  lv_obj_t *Wireless_label = lv_label_create(panel1);
  lv_label_set_text(Wireless_label, "Wireless scan");
  lv_obj_add_style(Wireless_label, &style_text_muted, 0);

  Wireless_Scan = lv_textarea_create(panel1);
  lv_textarea_set_one_line(Wireless_Scan, true);
  lv_textarea_set_placeholder_text(Wireless_Scan, "Wireless number");
  lv_obj_add_event_cb(Wireless_Scan, ta_event_cb, LV_EVENT_ALL, NULL);

  lv_obj_t *Backlight_label = lv_label_create(panel1);
  lv_label_set_text(Backlight_label, "Backlight brightness");
  lv_obj_add_style(Backlight_label, &style_text_muted, 0);

  Backlight_slider = lv_slider_create(panel1);
  lv_obj_add_flag(Backlight_slider, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_set_size(Backlight_slider, 200, 35);
  lv_obj_set_style_radius(Backlight_slider, 3, LV_PART_KNOB); // Adjust the value for more or less rounding
  lv_obj_set_style_bg_opa(Backlight_slider, LV_OPA_TRANSP, LV_PART_KNOB);
  // lv_obj_set_style_pad_all(Backlight_slider, 0, LV_PART_KNOB);
  lv_obj_set_style_bg_color(Backlight_slider, lv_color_hex(0xAAAAAA), LV_PART_KNOB);
  lv_obj_set_style_bg_color(Backlight_slider, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR);
  lv_obj_set_style_outline_width(Backlight_slider, 2, LV_PART_INDICATOR);
  lv_obj_set_style_outline_color(Backlight_slider, lv_color_hex(0xD3D3D3), LV_PART_INDICATOR);
  lv_slider_set_range(Backlight_slider, 5, Backlight_MAX);
  lv_slider_set_value(Backlight_slider, LCD_Backlight, LV_ANIM_ON);
  lv_obj_add_event_cb(Backlight_slider, Backlight_adjustment_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

  static lv_coord_t grid_main_col_dsc[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
  static lv_coord_t grid_main_row_dsc[] = {LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_CONTENT, LV_GRID_TEMPLATE_LAST};
  lv_obj_set_grid_dsc_array(parent, grid_main_col_dsc, grid_main_row_dsc);

  /*Create the top panel*/
  static lv_coord_t grid_1_col_dsc[] = {LV_GRID_CONTENT, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
  static lv_coord_t grid_1_row_dsc[] = {
      LV_GRID_CONTENT, /*Title*/
      5,               /*Separator*/
      LV_GRID_CONTENT, /*Box title*/
      40,              /*Box*/
      LV_GRID_CONTENT, /*Box title*/
      40,              /*Box*/
      LV_GRID_CONTENT, /*Box title*/
      40,              /*Box*/
      LV_GRID_CONTENT, /*Box title*/
      40,              /*Box*/
      LV_GRID_CONTENT, /*Box title*/
      40,              /*Box*/
      LV_GRID_CONTENT, /*Box title*/
      40,              /*Box*/
      LV_GRID_CONTENT, /*Box title*/
      40,              /*Box*/
      LV_GRID_TEMPLATE_LAST};

  lv_obj_set_grid_cell(panel1, LV_GRID_ALIGN_STRETCH, 0, 1, LV_GRID_ALIGN_START, 0, 1);
  lv_obj_set_grid_dsc_array(panel1, grid_1_col_dsc, grid_1_row_dsc);
  lv_obj_set_grid_cell(panel1_title, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);
  lv_obj_set_grid_cell(SD_label, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_START, 2, 1);
  lv_obj_set_grid_cell(SD_Size, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_CENTER, 3, 1);
  lv_obj_set_grid_cell(Flash_label, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_START, 4, 1);
  lv_obj_set_grid_cell(FlashSize, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_CENTER, 5, 1);
  lv_obj_set_grid_cell(BAT_label, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_START, 6, 1);
  lv_obj_set_grid_cell(BAT_Volts, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_CENTER, 7, 1);
  lv_obj_set_grid_cell(angle_label, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_START, 8, 1);
  lv_obj_set_grid_cell(Board_angle, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_CENTER, 9, 1);
  lv_obj_set_grid_cell(Time_label, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_START, 10, 1);
  lv_obj_set_grid_cell(RTC_Time, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_CENTER, 11, 1);
  lv_obj_set_grid_cell(Wireless_label, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_START, 12, 1);
  lv_obj_set_grid_cell(Wireless_Scan, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_CENTER, 13, 1);
  lv_obj_set_grid_cell(Backlight_label, LV_GRID_ALIGN_START, 1, 1, LV_GRID_ALIGN_START, 14, 1);
  lv_obj_set_grid_cell(Backlight_slider, LV_GRID_ALIGN_STRETCH, 1, 1, LV_GRID_ALIGN_CENTER, 15, 1);

  auto_step_timer = lv_timer_create(example1_increase_lvgl_tick, 100, NULL);
}

void IRAM_ATTR example1_increase_lvgl_tick(lv_timer_t *t)
{
  char buf[100];

  snprintf(buf, sizeof(buf), "%d MB\r\n", SDCard_Size);
  lv_textarea_set_placeholder_text(SD_Size, buf);
  snprintf(buf, sizeof(buf), "%d MB\r\n", Flash_Size);
  lv_textarea_set_placeholder_text(FlashSize, buf);
  snprintf(buf, sizeof(buf), "%.2f V\r\n", BAT_analogVolts);
  lv_textarea_set_placeholder_text(BAT_Volts, buf);
  snprintf(buf, sizeof(buf), "X:%.2f  Y:%.2f  Z:%.2f\r\n", Accel.x, Accel.y, Accel.z);
  lv_textarea_set_placeholder_text(Board_angle, buf);

  // snprintf(buf, sizeof(buf), "%d.%d.%d   %d:%d:%d\r\n",datetime.year,datetime.month,datetime.day,datetime.hour,datetime.minute,datetime.second);
  // lv_textarea_set_placeholder_text(RTC_Time, buf);

  if (Scan_finish)
    // snprintf(buf, sizeof(buf), "WIFI: %d    BLE: %d    ..Scan Finish.\r\n",WIFI_NUM,BLE_NUM);
    snprintf(buf, sizeof(buf), "WIFI: %d     ..Scan Finish.\r\n", WIFI_NUM);
  else
    snprintf(buf, sizeof(buf), "WIFI: %d  \r\n", WIFI_NUM);
  // snprintf(buf, sizeof(buf), "WIFI: %d    BLE: %d\r\n",WIFI_NUM,BLE_NUM);
  lv_textarea_set_placeholder_text(Wireless_Scan, buf);
  lv_slider_set_value(Backlight_slider, LCD_Backlight, LV_ANIM_ON);

  if (LCD_Backlight != 0)
  {
    BU_LCD_Backlight = LCD_Backlight;
  }

  LVGL_Backlight_adjustment(LCD_Backlight);
}

/*
static void Music_create(lv_obj_t * parent)
{
  static lv_obj_t * ctrl;
  original_screen_bg_color = lv_obj_get_style_bg_color(parent, 0);
  lv_obj_set_style_bg_color(parent, lv_color_hex(0x343247), 0);

  ctrl = _lv_demo_music_main_create(parent);
}
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static void color_changer_create(lv_obj_t *parent)
{
  static lv_palette_t palette[] = {
      LV_PALETTE_BLUE, LV_PALETTE_GREEN, LV_PALETTE_BLUE_GREY, LV_PALETTE_ORANGE,
      LV_PALETTE_RED, LV_PALETTE_PURPLE, LV_PALETTE_TEAL, _LV_PALETTE_LAST};

  lv_obj_t *color_cont = lv_obj_create(parent);
  lv_obj_remove_style_all(color_cont);
  lv_obj_set_flex_flow(color_cont, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(color_cont, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_add_flag(color_cont, LV_OBJ_FLAG_FLOATING);

  lv_obj_set_style_bg_color(color_cont, lv_color_white(), 0);
  lv_obj_set_style_pad_right(color_cont, disp_size == DISP_SMALL ? LV_DPX(47) : LV_DPX(55), 0);
  lv_obj_set_style_bg_opa(color_cont, LV_OPA_COVER, 0);
  lv_obj_set_style_radius(color_cont, LV_RADIUS_CIRCLE, 0);

  if (disp_size == DISP_SMALL)
    lv_obj_set_size(color_cont, LV_DPX(52), LV_DPX(52));
  else
    lv_obj_set_size(color_cont, LV_DPX(60), LV_DPX(60));

  lv_obj_align(color_cont, LV_ALIGN_BOTTOM_RIGHT, -LV_DPX(10), -LV_DPX(10));

  uint32_t i;
  for (i = 0; palette[i] != _LV_PALETTE_LAST; i++)
  {
    lv_obj_t *c = lv_btn_create(color_cont);
    lv_obj_set_style_bg_color(c, lv_palette_main(palette[i]), 0);
    lv_obj_set_style_radius(c, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_opa(c, LV_OPA_TRANSP, 0);
    lv_obj_set_size(c, 20, 20);
    lv_obj_add_event_cb(c, color_event_cb, LV_EVENT_ALL, &palette[i]);
    lv_obj_clear_flag(c, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
  }

  lv_obj_t *btn = lv_btn_create(parent);
  lv_obj_add_flag(btn, LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_CLICKABLE);
  lv_obj_set_style_bg_color(btn, lv_color_white(), LV_STATE_CHECKED);
  lv_obj_set_style_pad_all(btn, 10, 0);
  lv_obj_set_style_radius(btn, LV_RADIUS_CIRCLE, 0);
  lv_obj_add_event_cb(btn, color_changer_event_cb, LV_EVENT_ALL, color_cont);
  lv_obj_set_style_shadow_width(btn, 0, 0);
  lv_obj_set_style_bg_img_src(btn, LV_SYMBOL_TINT, 0);

  if (disp_size == DISP_SMALL)
  {
    lv_obj_set_size(btn, LV_DPX(42), LV_DPX(42));
    lv_obj_align(btn, LV_ALIGN_BOTTOM_RIGHT, -LV_DPX(15), -LV_DPX(15));
  }
  else
  {
    lv_obj_set_size(btn, LV_DPX(50), LV_DPX(50));
    lv_obj_align(btn, LV_ALIGN_BOTTOM_RIGHT, -LV_DPX(15), -LV_DPX(15));
  }
}

static void color_changer_anim_cb(void *var, int32_t v)
{
  lv_obj_t *obj = (lv_obj_t *)var;
  lv_coord_t max_w = lv_obj_get_width(lv_obj_get_parent(obj)) - LV_DPX(20);
  lv_coord_t w;

  if (disp_size == DISP_SMALL)
  {
    w = lv_map(v, 0, 256, LV_DPX(52), max_w);
    lv_obj_set_width(obj, w);
    lv_obj_align(obj, LV_ALIGN_BOTTOM_RIGHT, -LV_DPX(10), -LV_DPX(10));
  }
  else
  {
    w = lv_map(v, 0, 256, LV_DPX(60), max_w);
    lv_obj_set_width(obj, w);
    lv_obj_align(obj, LV_ALIGN_BOTTOM_RIGHT, -LV_DPX(10), -LV_DPX(10));
  }

  if (v > LV_OPA_COVER)
    v = LV_OPA_COVER;

  uint32_t i;
  for (i = 0; i < lv_obj_get_child_cnt(obj); i++)
  {
    lv_obj_set_style_opa(lv_obj_get_child(obj, i), v, 0);
  }
}

static void color_changer_event_cb(lv_event_t *e)
{
  if (lv_event_get_code(e) == LV_EVENT_CLICKED)
  {
    lv_obj_t *color_cont = (lv_obj_t *)lv_event_get_user_data(e);
    if (lv_obj_get_width(color_cont) < LV_HOR_RES / 2)
    {
      lv_anim_t a;
      lv_anim_init(&a);
      lv_anim_set_var(&a, color_cont);
      lv_anim_set_exec_cb(&a, color_changer_anim_cb);
      lv_anim_set_values(&a, 0, 256);
      lv_anim_set_time(&a, 200);
      lv_anim_start(&a);
    }
    else
    {
      lv_anim_t a;
      lv_anim_init(&a);
      lv_anim_set_var(&a, color_cont);
      lv_anim_set_exec_cb(&a, color_changer_anim_cb);
      lv_anim_set_values(&a, 256, 0);
      lv_anim_set_time(&a, 200);
      lv_anim_start(&a);
    }
  }
}
static void color_event_cb(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *obj = lv_event_get_target(e);

  if (code == LV_EVENT_FOCUSED)
  {
    lv_obj_t *color_cont = lv_obj_get_parent(obj);
    if (lv_obj_get_width(color_cont) < LV_HOR_RES / 2)
    {
      lv_anim_t a;
      lv_anim_init(&a);
      lv_anim_set_var(&a, color_cont);
      lv_anim_set_exec_cb(&a, color_changer_anim_cb);
      lv_anim_set_values(&a, 0, 256);
      lv_anim_set_time(&a, 200);
      lv_anim_start(&a);
    }
  }
  else if (code == LV_EVENT_CLICKED)
  {
    lv_palette_t *palette_primary = (lv_palette_t *)lv_event_get_user_data(e);
    lv_palette_t palette_secondary = (lv_palette_t)((*palette_primary) + 3); /*Use another palette as secondary*/
    if (palette_secondary >= _LV_PALETTE_LAST)
      palette_secondary = (lv_palette_t)(0);
#if LV_USE_THEME_DEFAULT
    lv_theme_default_init(NULL, lv_palette_main(*palette_primary), lv_palette_main(palette_secondary),
                          LV_THEME_DEFAULT_DARK, font_normal);
#endif
    lv_color_t color = lv_palette_main(*palette_primary);
    lv_style_set_text_color(&style_icon, color);
    lv_chart_set_series_color(chart1, ser1, color);
    lv_chart_set_series_color(chart2, ser3, color);
  }
}

void Backlight_adjustment_event_cb(lv_event_t *e)
{
  uint8_t Backlight = lv_slider_get_value(lv_event_get_target(e));
  if (Backlight >= 0 && Backlight <= Backlight_MAX)
  {
    lv_slider_set_value(Backlight_slider, Backlight, LV_ANIM_ON);
    LCD_Backlight = Backlight;
    LVGL_Backlight_adjustment(Backlight);
  }
  else
    printf("Volume out of range: %d\n", Volume);
}

static void ta_event_cb(lv_event_t *e)
{
}

static void birthday_event_cb(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *ta = lv_event_get_target(e);

  if (code == LV_EVENT_FOCUSED)
  {
    if (lv_indev_get_type(lv_indev_get_act()) == LV_INDEV_TYPE_POINTER)
    {
      if (calendar == NULL)
      {
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        calendar = lv_calendar_create(lv_layer_top());
        lv_obj_set_style_bg_opa(lv_layer_top(), LV_OPA_50, 0);
        lv_obj_set_style_bg_color(lv_layer_top(), lv_palette_main(LV_PALETTE_GREY), 0);
        if (disp_size == DISP_SMALL)
          lv_obj_set_size(calendar, 180, 200);
        else if (disp_size == DISP_MEDIUM)
          lv_obj_set_size(calendar, 200, 220);
        else
          lv_obj_set_size(calendar, 300, 330);
        lv_calendar_set_showed_date(calendar, 1990, 01);
        lv_obj_align(calendar, LV_ALIGN_CENTER, 0, 30);
        lv_obj_add_event_cb(calendar, calendar_event_cb, LV_EVENT_ALL, ta);

        lv_calendar_header_dropdown_create(calendar);
      }
    }
  }
}

static void calendar_event_cb(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *ta = (lv_obj_t *)lv_event_get_user_data(e);
  lv_obj_t *obj = (lv_obj_t *)lv_event_get_current_target(e);
  if (code == LV_EVENT_VALUE_CHANGED)
  {
    lv_calendar_date_t d;
    lv_calendar_get_pressed_date(obj, &d);
    char buf[32];
    lv_snprintf(buf, sizeof(buf), "%02d.%02d.%d", d.day, d.month, d.year);
    lv_textarea_set_text(ta, buf);

    lv_obj_del(calendar);
    calendar = NULL;
    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_bg_opa(lv_layer_top(), LV_OPA_TRANSP, 0);
  }
}

void LVGL_Backlight_adjustment(uint8_t Backlight)
{
  Set_Backlight(Backlight);
}
