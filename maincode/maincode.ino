// определение режима соединения и подключение библиотеки RemoteXY 
#define REMOTEXY_MODE__ESP8266WIFI_LIB
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// настройки соединения 
#define REMOTEXY_WIFI_SSID "kvm"
#define REMOTEXY_WIFI_PASSWORD "75769906"
#define REMOTEXY_SERVER_PORT 6377


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


void setup() 
{
  RemoteXY_Init (); 
  
  pinMode (PIN_SWITCH_1, OUTPUT);
  
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1==0)?LOW:HIGH);
  
  // TODO you loop code
  // используйте структуру RemoteXY для передачи данных
  // не используйте функцию delay() 


}