// определение режима соединения и подключение библиотеки RemoteXY 
#define REMOTEXY_MODE__ESP8266WIFI_LIB
#include <ESP8266WiFi.h>
#include <RemoteXY.h>
// настройки соединения 
#define REMOTEXY_WIFI_SSID "tpk"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377
void savecolor(int red, int green, int blue, int arrname);
// конфигурация интерфейса  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 58 bytes
  { 255,6,0,3,0,51,0,16,180,1,3,132,4,58,34,9,2,26,6,0,
  2,15,38,38,2,26,65,113,44,17,13,35,1,0,42,56,17,17,2,31,
  0,2,0,3,72,33,13,2,26,31,31,79,78,0,79,70,70,0 };
  
// структура определяет все переменные и события вашего интерфейса управления 
struct {

    // input variables
  uint8_t select_1; // =0 если переключатель в положении A, =1 если в положении B, =2 если в положении C, ... 
  uint8_t rgb_1_r; // =0..255 значение Красного цвета 
  uint8_t rgb_1_g; // =0..255 значение Зеленого цвета 
  uint8_t rgb_1_b; // =0..255 значение Синего цвета 
  uint8_t button_1; // =1 если кнопка нажата, иначе =0 
  uint8_t switch_1; // =1 если переключатель включен и =0 если отключен 

    // output variables
  uint8_t led_1_r; // =0..255 яркость красного цвета индикатора 
  uint8_t led_1_g; // =0..255 яркость зеленого цвета индикатора 
  uint8_t led_1_b; // =0..255 яркость синего цвета индикатора 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_1 D2
#define S0 D4
#define S1 D5
#define S2 D6
#define S3 D7
#define sensorOut D8
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int redColor = 0;
int greenColor = 0;
int blueColor = 0;
int color1_r;
int color1_g;
int color1_b;
int color2_r;
int color2_g;
int color2_b;
int color3_r;
int color3_g;
int color3_b;
int color4_r;
int color4_g;
int color4_b;

 void savecolor(int red, int green, int blue, int arrname) 
  {
    switch(arrname) {
      case 0: {
        color1_r = red;
        color1_g = green;
        color1_b = blue;
      break;}
      case 1: {
        color2_r = red;
        color2_g = green;
        color2_b = blue;
      break;}
      case 2: {
        color3_r = red;
        color3_g = green;
        color3_b = blue;
      break;}
      case 3: {
        color4_r = red;
        color4_g = green;
        color4_b = blue;
      break;}
    } 

  }

void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_1, OUTPUT);
  
  // TODO you setup code 
  Serial.begin(9600);
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);

  // TODO you loop code
  switch(RemoteXY.select_1){
    case 0: {
      RemoteXY.led_1_r = color1_r;
      RemoteXY.led_1_g = color1_g;
      RemoteXY.led_1_b = color1_b;
      break;
    }
    case 1: {
      RemoteXY.led_1_r = color2_r;
      RemoteXY.led_1_g = color2_g;
      RemoteXY.led_1_b = color2_b;
      break;
    }
    case 2: {
      RemoteXY.led_1_r = color3_r;
      RemoteXY.led_1_g = color3_g;
      RemoteXY.led_1_b = color3_b;
      break;
    }
    case 3: {
      RemoteXY.led_1_r = color4_r;
      RemoteXY.led_1_g = color4_g;
      RemoteXY.led_1_b = color4_b;
      break;
    }
  }
  if (RemoteXY.button_1!=0) {
    delay(300);
    savecolor(RemoteXY.rgb_1_r, RemoteXY.rgb_1_g, RemoteXY.rgb_1_b, RemoteXY.select_1);
  }


}
