// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
using namespace text_sensor;
using namespace binary_sensor;
logger::Logger *logger_logger;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_3;
status_led::StatusLED *status_led_statusled;
wifi::WiFiComponent *wifi_wificomponent;
mdns::MDNSComponent *mdns_mdnscomponent;
ota::OTAComponent *ota_otacomponent;
api::APIServer *api_apiserver;
using namespace api;
using namespace number;
using namespace sensor;
StartupTrigger *startuptrigger;
Automation<> *automation;
uart::UARTWriteAction<> *uart_uartwriteaction;
preferences::IntervalSyncer *preferences_intervalsyncer;
using namespace uart;
uart::ESP32ArduinoUARTComponent *LD1115H_UART_BUS;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_2;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin;
interval::IntervalTrigger *interval_intervaltrigger;
Automation<> *automation_2;
template_::TemplateNumber *presence_delay_off;
template_::TemplateNumber *LD1115H_TH1;
Automation<float> *automation_3;
uart::UARTWriteAction<float> *uart_uartwriteaction_3;
template_::TemplateNumber *LD1115H_TH2;
Automation<float> *automation_4;
uart::UARTWriteAction<float> *uart_uartwriteaction_4;
template_::TemplateNumber *LD1115H_Clear_Time;
template_::TemplateNumber *LD1115H_Mov_Time;
wifi_signal::WiFiSignalSensor *wifi_signal_wifisignalsensor;
uptime::UptimeSensor *uptime_uptimesensor;
template_::TemplateSensor *LD1115H_Spectral;
template_::TemplateSensor *LD1115H_Signal;
sensor::SlidingWindowMovingAverageFilter *sensor_slidingwindowmovingaveragefilter;
sensor::HeartbeatFilter *sensor_heartbeatfilter;
wifi_info::IPAddressWiFiInfo *wifi_info_ipaddresswifiinfo;
wifi_info::SSIDWiFiInfo *wifi_info_ssidwifiinfo;
wifi_info::BSSIDWiFiInfo *wifi_info_bssidwifiinfo;
wifi_info::MacAddressWifiInfo *wifi_info_macaddresswifiinfo;
serial::SerialTextSensor *LD1115H_UART_Text;
text_sensor::TextSensorStateTrigger *text_sensor_textsensorstatetrigger;
Automation<std::string> *automation_5;
template_::TemplateTextSensor *LD1115H_Occupancy;
status::StatusBinarySensor *status_statusbinarysensor;
template_::TemplateBinarySensor *LD1115H_MovOcc_Binary;
binary_sensor::StateTrigger *binary_sensor_statetrigger;
Automation<bool> *automation_6;
template_::TemplateBinarySensor *LD1115H_Mov_Binary;
gpio::GPIOBinarySensor *pir_sensor;
binary_sensor::StateTrigger *binary_sensor_statetrigger_2;
Automation<bool> *automation_7;
template_::TemplateBinarySensor *Unified_Presence;
binary_sensor::StateTrigger *binary_sensor_statetrigger_3;
Automation<bool> *automation_8;
DelayAction<bool> *delayaction;
binary_sensor::BinarySensorPublishAction<bool> *binary_sensor_binarysensorpublishaction_3;
uart::UARTWriteAction<> *uart_uartwriteaction_2;
binary_sensor::BinarySensorPublishAction<bool> *binary_sensor_binarysensorpublishaction;
binary_sensor::BinarySensorPublishAction<bool> *binary_sensor_binarysensorpublishaction_2;
esp32::ESP32InternalGPIOPin *esp32_esp32internalgpiopin_4;
globals::GlobalsComponent<time_t> *LD1115H_Last_Time;
globals::GlobalsComponent<time_t> *LD1115H_Last_Mov_Time;
globals::GlobalsComponent<bool> *LD1115H_Clearence_Status;
LambdaAction<> *lambdaaction;
LambdaAction<std::string> *lambdaaction_2;
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  // esphome:
  //   name: lab-module
  //   on_boot:
  //   - priority: -200.0
  //     then:
  //     - uart.write:
  //         id: LD1115H_UART_BUS
  //         data: !lambda |-
  //           std::string th1st = "th1=" + str_sprintf("%.0f",id(LD1115H_TH1).state) +" \n";
  //           return std::vector<uint8_t>(th1st.begin(), th1st.end());
  //       type_id: uart_uartwriteaction
  //     - uart.write:
  //         id: LD1115H_UART_BUS
  //         data: !lambda |-
  //           std::string th2st = "th2=" + str_sprintf("%.0f",id(LD1115H_TH2).state) +" \n";
  //           return std::vector<uint8_t>(th2st.begin(), th2st.end());
  //       type_id: uart_uartwriteaction_2
  //     automation_id: automation
  //     trigger_id: startuptrigger
  //   build_path: .esphome/build/lab-module
  //   friendly_name: ''
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  //   min_version: 2023.3.1
  App.pre_setup("lab-module", "", "", __DATE__ ", " __TIME__, false);
  // text_sensor:
  // binary_sensor:
  // logger:
  //   level: DEBUG
  //   baud_rate: 0
  //   id: logger_logger
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   hardware_uart: UART0
  //   logs: {}
  logger_logger = new logger::Logger(0, 512);
  logger_logger->set_uart_selection(logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  logger_logger->set_component_source("logger");
  App.register_component(logger_logger);
  // status_led:
  //   pin:
  //     number: 2
  //     inverted: false
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esp32_esp32internalgpiopin_3
  //     drive_strength: 20.0
  //   id: status_led_statusled
  esp32_esp32internalgpiopin_3 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_3->set_pin(::GPIO_NUM_2);
  esp32_esp32internalgpiopin_3->set_inverted(false);
  esp32_esp32internalgpiopin_3->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_3->set_flags(gpio::Flags::FLAG_OUTPUT);
  status_led_statusled = new status_led::StatusLED(esp32_esp32internalgpiopin_3);
  status_led_statusled->set_component_source("status_led");
  App.register_component(status_led_statusled);
  status_led_statusled->pre_setup();
  // wifi:
  //   ap:
  //     ssid: Lab-Module Fallback Hotspot
  //     password: KK0jK0sqdVyP
  //     id: wifi_wifiap
  //     ap_timeout: 1min
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: LIGHT
  //   fast_connect: false
  //   networks:
  //   - ssid: !secret 'wifi_ssid'
  //     password: !secret 'wifi_password'
  //     id: wifi_wifiap_2
  //     priority: 0.0
  //   use_address: lab-module.local
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("lab-module.local");
  {
  wifi::WiFiAP wifi_wifiap_2 = wifi::WiFiAP();
  wifi_wifiap_2.set_ssid("YourSSID");
  wifi_wifiap_2.set_password("YourPassword");
  wifi_wifiap_2.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap_2);
  }
  {
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("Lab-Module Fallback Hotspot");
  wifi_wifiap.set_password("YourPassword");
  wifi_wificomponent->set_ap(wifi_wifiap);
  }
  wifi_wificomponent->set_ap_timeout(60000);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_LIGHT);
  wifi_wificomponent->set_fast_connect(false);
  wifi_wificomponent->set_component_source("wifi");
  App.register_component(wifi_wificomponent);
  // mdns:
  //   id: mdns_mdnscomponent
  //   disabled: false
  //   services: []
  mdns_mdnscomponent = new mdns::MDNSComponent();
  mdns_mdnscomponent->set_component_source("mdns");
  App.register_component(mdns_mdnscomponent);
  // ota:
  //   password: 12345
  //   id: ota_otacomponent
  //   safe_mode: true
  //   port: 3232
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(3232);
  ota_otacomponent->set_auth_password("12345");
  ota_otacomponent->set_component_source("ota");
  App.register_component(ota_otacomponent);
  if (ota_otacomponent->should_enter_safe_mode(10, 300000)) return;
  // api:
  //   encryption:
  //     key: 12345=
  //   id: api_apiserver
  //   port: 6053
  //   password: ''
  //   reboot_timeout: 15min
  api_apiserver = new api::APIServer();
  api_apiserver->set_component_source("api");
  App.register_component(api_apiserver);
  api_apiserver->set_port(6053);
  api_apiserver->set_password("");
  api_apiserver->set_reboot_timeout(900000);
  api_apiserver->set_noise_psk({27, 168, 137, 110, 24, 214, 60, 121, 44, 221, 85, 237, 218, 6, 48, 226, 99, 129, 172, 184, 254, 197, 186, 141, 26, 252, 110, 155, 0, 77, 245, 210});
  // number:
  // sensor:
  startuptrigger = new StartupTrigger(-200.0f);
  startuptrigger->set_component_source("esphome.coroutine");
  App.register_component(startuptrigger);
  automation = new Automation<>(startuptrigger);
  uart_uartwriteaction = new uart::UARTWriteAction<>();
  // substitutions:
  //   devicename: lab-module
  //   upper_devicename: Radar
  //   pir_devicename: PIR
  // esp32:
  //   board: wemos_d1_mini32
  //   framework:
  //     version: 2.0.5
  //     source: ~3.20005.0
  //     platform_version: platformio/espressif32 @ 5.2.0
  //     type: arduino
  //   variant: ESP32
  // preferences:
  //   id: preferences_intervalsyncer
  //   flash_write_interval: 60s
  preferences_intervalsyncer = new preferences::IntervalSyncer();
  preferences_intervalsyncer->set_write_interval(60000);
  preferences_intervalsyncer->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer);
  // external_components:
  //   - source:
  //       url: https:github.com/ssieb/custom_components
  //       type: git
  //     components:
  //     - serial
  //     refresh: 1d
  // uart:
  //   id: LD1115H_UART_BUS
  //   rx_pin:
  //     number: 16
  //     mode:
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     inverted: false
  //     id: esp32_esp32internalgpiopin
  //     drive_strength: 20.0
  //   tx_pin:
  //     number: 17
  //     mode:
  //       output: true
  //       input: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     inverted: false
  //     id: esp32_esp32internalgpiopin_2
  //     drive_strength: 20.0
  //   baud_rate: 115200
  //   data_bits: 8
  //   stop_bits: 1
  //   parity: NONE
  //   setup_priority: 200.0
  //   rx_buffer_size: 256
  LD1115H_UART_BUS = new uart::ESP32ArduinoUARTComponent();
  LD1115H_UART_BUS->set_setup_priority(200.0f);
  LD1115H_UART_BUS->set_component_source("uart");
  App.register_component(LD1115H_UART_BUS);
  LD1115H_UART_BUS->set_baud_rate(115200);
  esp32_esp32internalgpiopin_2 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_2->set_pin(::GPIO_NUM_17);
  esp32_esp32internalgpiopin_2->set_inverted(false);
  esp32_esp32internalgpiopin_2->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_2->set_flags(gpio::Flags::FLAG_OUTPUT);
  LD1115H_UART_BUS->set_tx_pin(esp32_esp32internalgpiopin_2);
  esp32_esp32internalgpiopin = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin->set_pin(::GPIO_NUM_16);
  esp32_esp32internalgpiopin->set_inverted(false);
  esp32_esp32internalgpiopin->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin->set_flags(gpio::Flags::FLAG_INPUT);
  LD1115H_UART_BUS->set_rx_pin(esp32_esp32internalgpiopin);
  LD1115H_UART_BUS->set_rx_buffer_size(256);
  LD1115H_UART_BUS->set_stop_bits(1);
  LD1115H_UART_BUS->set_data_bits(8);
  LD1115H_UART_BUS->set_parity(uart::UART_CONFIG_PARITY_NONE);
  // interval:
  //   - interval: 1s
  //     setup_priority: -200.0
  //     then:
  //     - lambda: !lambda |-
  //         if ((time(NULL)-id(LD1115H_Last_Time))>id(LD1115H_Clear_Time).state) {
  //           if ((id(LD1115H_Clearence_Status) == false) || (id(LD1115H_Occupancy).state != "Clearance")) {
  //             id(LD1115H_Occupancy).publish_state("Clearance");
  //             id(LD1115H_Clearence_Status) = true;
  //           }
  //           if (id(LD1115H_MovOcc_Binary).state == true) {
  //             id(LD1115H_MovOcc_Binary).publish_state(false);
  //           }
  //           if (id(LD1115H_Mov_Binary).state == true) {
  //             id(LD1115H_Mov_Binary).publish_state(false);
  //           }
  //         }
  //       type_id: lambdaaction
  //     trigger_id: trigger
  //     automation_id: automation_2
  //     id: interval_intervaltrigger
  interval_intervaltrigger = new interval::IntervalTrigger();
  interval_intervaltrigger->set_setup_priority(-200.0f);
  interval_intervaltrigger->set_component_source("interval");
  App.register_component(interval_intervaltrigger);
  automation_2 = new Automation<>(interval_intervaltrigger);
  // number.template:
  //   platform: template
  //   name: presence_delay_off
  //   id: presence_delay_off
  //   icon: mdi:cogs
  //   optimistic: true
  //   restore_value: true
  //   initial_value: 300.0
  //   min_value: 0.5
  //   max_value: 3600.0
  //   step: 0.5
  //   disabled_by_default: false
  //   mode: AUTO
  //   update_interval: 60s
  presence_delay_off = new template_::TemplateNumber();
  presence_delay_off->set_update_interval(60000);
  presence_delay_off->set_component_source("template.number");
  App.register_component(presence_delay_off);
  App.register_number(presence_delay_off);
  presence_delay_off->set_name("presence_delay_off");
  presence_delay_off->set_disabled_by_default(false);
  presence_delay_off->set_icon("mdi:cogs");
  presence_delay_off->traits.set_min_value(0.5f);
  presence_delay_off->traits.set_max_value(3600.0f);
  presence_delay_off->traits.set_step(0.5f);
  presence_delay_off->traits.set_mode(number::NUMBER_MODE_AUTO);
  presence_delay_off->set_optimistic(true);
  presence_delay_off->set_initial_value(300.0f);
  presence_delay_off->set_restore_value(true);
  // number.template:
  //   platform: template
  //   name: Motion Sensitivity
  //   id: LD1115H_TH1
  //   icon: mdi:cogs
  //   optimistic: true
  //   restore_value: true
  //   initial_value: 120.0
  //   min_value: 20.0
  //   max_value: 1200.0
  //   step: 10.0
  //   set_action:
  //     then:
  //     - uart.write:
  //         id: LD1115H_UART_BUS
  //         data: !lambda |-
  //           std::string th1st = "th1=" + str_sprintf("%.0f",x) +" \n";
  //           return std::vector<uint8_t>(th1st.begin(), th1st.end());
  //       type_id: uart_uartwriteaction_3
  //     trigger_id: trigger_2
  //     automation_id: automation_3
  //   disabled_by_default: false
  //   mode: AUTO
  //   update_interval: 60s
  LD1115H_TH1 = new template_::TemplateNumber();
  LD1115H_TH1->set_update_interval(60000);
  LD1115H_TH1->set_component_source("template.number");
  App.register_component(LD1115H_TH1);
  App.register_number(LD1115H_TH1);
  LD1115H_TH1->set_name("Motion Sensitivity");
  LD1115H_TH1->set_disabled_by_default(false);
  LD1115H_TH1->set_icon("mdi:cogs");
  LD1115H_TH1->traits.set_min_value(20.0f);
  LD1115H_TH1->traits.set_max_value(1200.0f);
  LD1115H_TH1->traits.set_step(10.0f);
  LD1115H_TH1->traits.set_mode(number::NUMBER_MODE_AUTO);
  LD1115H_TH1->set_optimistic(true);
  LD1115H_TH1->set_initial_value(120.0f);
  LD1115H_TH1->set_restore_value(true);
  automation_3 = new Automation<float>(LD1115H_TH1->get_set_trigger());
  uart_uartwriteaction_3 = new uart::UARTWriteAction<float>();
  uart_uartwriteaction_3->set_parent(LD1115H_UART_BUS);
  uart_uartwriteaction_3->set_data_template([=](float x) -> std::vector<uint8_t> {
      #line 148 "/config/esphome/lab-module.yaml"
      std::string th1st = "th1=" + str_sprintf("%.0f",x) +" \n";
      return std::vector<uint8_t>(th1st.begin(), th1st.end());
  });
  automation_3->add_actions({uart_uartwriteaction_3});
  // number.template:
  //   platform: template
  //   name: Presence Sensitivity
  //   id: LD1115H_TH2
  //   icon: mdi:cogs
  //   optimistic: true
  //   restore_value: true
  //   initial_value: 250.0
  //   min_value: 50.0
  //   max_value: 2500.0
  //   step: 10.0
  //   set_action:
  //     then:
  //     - uart.write:
  //         id: LD1115H_UART_BUS
  //         data: !lambda |-
  //           std::string th2st = "th2=" + str_sprintf("%.0f",x) +" \n";
  //           return std::vector<uint8_t>(th2st.begin(), th2st.end());
  //       type_id: uart_uartwriteaction_4
  //     trigger_id: trigger_3
  //     automation_id: automation_4
  //   disabled_by_default: false
  //   mode: AUTO
  //   update_interval: 60s
  LD1115H_TH2 = new template_::TemplateNumber();
  LD1115H_TH2->set_update_interval(60000);
  LD1115H_TH2->set_component_source("template.number");
  App.register_component(LD1115H_TH2);
  App.register_number(LD1115H_TH2);
  LD1115H_TH2->set_name("Presence Sensitivity");
  LD1115H_TH2->set_disabled_by_default(false);
  LD1115H_TH2->set_icon("mdi:cogs");
  LD1115H_TH2->traits.set_min_value(50.0f);
  LD1115H_TH2->traits.set_max_value(2500.0f);
  LD1115H_TH2->traits.set_step(10.0f);
  LD1115H_TH2->traits.set_mode(number::NUMBER_MODE_AUTO);
  LD1115H_TH2->set_optimistic(true);
  LD1115H_TH2->set_initial_value(250.0f);
  LD1115H_TH2->set_restore_value(true);
  automation_4 = new Automation<float>(LD1115H_TH2->get_set_trigger());
  uart_uartwriteaction_4 = new uart::UARTWriteAction<float>();
  uart_uartwriteaction_4->set_parent(LD1115H_UART_BUS);
  uart_uartwriteaction_4->set_data_template([=](float x) -> std::vector<uint8_t> {
      #line 165 "/config/esphome/lab-module.yaml"
      std::string th2st = "th2=" + str_sprintf("%.0f",x) +" \n";
      return std::vector<uint8_t>(th2st.begin(), th2st.end());
  });
  automation_4->add_actions({uart_uartwriteaction_4});
  // number.template:
  //   platform: template
  //   name: Radar Clear Time
  //   id: LD1115H_Clear_Time
  //   icon: mdi:cogs
  //   optimistic: true
  //   restore_value: true
  //   initial_value: 5.0
  //   min_value: 0.5
  //   max_value: 20.0
  //   step: 0.5
  //   disabled_by_default: false
  //   mode: AUTO
  //   update_interval: 60s
  LD1115H_Clear_Time = new template_::TemplateNumber();
  LD1115H_Clear_Time->set_update_interval(60000);
  LD1115H_Clear_Time->set_component_source("template.number");
  App.register_component(LD1115H_Clear_Time);
  App.register_number(LD1115H_Clear_Time);
  LD1115H_Clear_Time->set_name("Radar Clear Time");
  LD1115H_Clear_Time->set_disabled_by_default(false);
  LD1115H_Clear_Time->set_icon("mdi:cogs");
  LD1115H_Clear_Time->traits.set_min_value(0.5f);
  LD1115H_Clear_Time->traits.set_max_value(20.0f);
  LD1115H_Clear_Time->traits.set_step(0.5f);
  LD1115H_Clear_Time->traits.set_mode(number::NUMBER_MODE_AUTO);
  LD1115H_Clear_Time->set_optimistic(true);
  LD1115H_Clear_Time->set_initial_value(5.0f);
  LD1115H_Clear_Time->set_restore_value(true);
  // number.template:
  //   platform: template
  //   name: Radar Mov Time
  //   id: LD1115H_Mov_Time
  //   icon: mdi:cogs
  //   optimistic: true
  //   restore_value: true
  //   initial_value: 1.0
  //   min_value: 0.5
  //   max_value: 10.0
  //   step: 0.5
  //   disabled_by_default: false
  //   mode: AUTO
  //   update_interval: 60s
  LD1115H_Mov_Time = new template_::TemplateNumber();
  LD1115H_Mov_Time->set_update_interval(60000);
  LD1115H_Mov_Time->set_component_source("template.number");
  App.register_component(LD1115H_Mov_Time);
  App.register_number(LD1115H_Mov_Time);
  LD1115H_Mov_Time->set_name("Radar Mov Time");
  LD1115H_Mov_Time->set_disabled_by_default(false);
  LD1115H_Mov_Time->set_icon("mdi:cogs");
  LD1115H_Mov_Time->traits.set_min_value(0.5f);
  LD1115H_Mov_Time->traits.set_max_value(10.0f);
  LD1115H_Mov_Time->traits.set_step(0.5f);
  LD1115H_Mov_Time->traits.set_mode(number::NUMBER_MODE_AUTO);
  LD1115H_Mov_Time->set_optimistic(true);
  LD1115H_Mov_Time->set_initial_value(1.0f);
  LD1115H_Mov_Time->set_restore_value(true);
  // sensor.wifi_signal:
  //   platform: wifi_signal
  //   name: Radar WiFi Signal
  //   update_interval: 60s
  //   disabled_by_default: false
  //   force_update: false
  //   id: wifi_signal_wifisignalsensor
  //   unit_of_measurement: dBm
  //   accuracy_decimals: 0
  //   device_class: signal_strength
  //   state_class: measurement
  //   entity_category: diagnostic
  wifi_signal_wifisignalsensor = new wifi_signal::WiFiSignalSensor();
  App.register_sensor(wifi_signal_wifisignalsensor);
  wifi_signal_wifisignalsensor->set_name("Radar WiFi Signal");
  wifi_signal_wifisignalsensor->set_disabled_by_default(false);
  wifi_signal_wifisignalsensor->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  wifi_signal_wifisignalsensor->set_device_class("signal_strength");
  wifi_signal_wifisignalsensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  wifi_signal_wifisignalsensor->set_unit_of_measurement("dBm");
  wifi_signal_wifisignalsensor->set_accuracy_decimals(0);
  wifi_signal_wifisignalsensor->set_force_update(false);
  wifi_signal_wifisignalsensor->set_update_interval(60000);
  wifi_signal_wifisignalsensor->set_component_source("wifi_signal.sensor");
  App.register_component(wifi_signal_wifisignalsensor);
  // sensor.uptime:
  //   platform: uptime
  //   name: Radar Uptime
  //   disabled_by_default: false
  //   force_update: false
  //   id: uptime_uptimesensor
  //   unit_of_measurement: s
  //   icon: mdi:timer-outline
  //   accuracy_decimals: 0
  //   device_class: duration
  //   state_class: total_increasing
  //   entity_category: diagnostic
  //   update_interval: 60s
  uptime_uptimesensor = new uptime::UptimeSensor();
  App.register_sensor(uptime_uptimesensor);
  uptime_uptimesensor->set_name("Radar Uptime");
  uptime_uptimesensor->set_disabled_by_default(false);
  uptime_uptimesensor->set_icon("mdi:timer-outline");
  uptime_uptimesensor->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  uptime_uptimesensor->set_device_class("duration");
  uptime_uptimesensor->set_state_class(sensor::STATE_CLASS_TOTAL_INCREASING);
  uptime_uptimesensor->set_unit_of_measurement("s");
  uptime_uptimesensor->set_accuracy_decimals(0);
  uptime_uptimesensor->set_force_update(false);
  uptime_uptimesensor->set_update_interval(60000);
  uptime_uptimesensor->set_component_source("uptime.sensor");
  App.register_component(uptime_uptimesensor);
  // sensor.template:
  //   platform: template
  //   name: Radar Spectral line
  //   id: LD1115H_Spectral
  //   icon: mdi:radar
  //   unit_of_measurement: ''
  //   accuracy_decimals: 0
  //   disabled_by_default: false
  //   force_update: false
  //   update_interval: 60s
  LD1115H_Spectral = new template_::TemplateSensor();
  App.register_sensor(LD1115H_Spectral);
  LD1115H_Spectral->set_name("Radar Spectral line");
  LD1115H_Spectral->set_disabled_by_default(false);
  LD1115H_Spectral->set_icon("mdi:radar");
  LD1115H_Spectral->set_unit_of_measurement("");
  LD1115H_Spectral->set_accuracy_decimals(0);
  LD1115H_Spectral->set_force_update(false);
  LD1115H_Spectral->set_update_interval(60000);
  LD1115H_Spectral->set_component_source("template.sensor");
  App.register_component(LD1115H_Spectral);
  // sensor.template:
  //   platform: template
  //   name: Radar Signal Strength
  //   id: LD1115H_Signal
  //   icon: mdi:signal-distance-variant
  //   unit_of_measurement: ''
  //   accuracy_decimals: 0
  //   filters:
  //   - sliding_window_moving_average:
  //       window_size: 8
  //       send_every: 2
  //       send_first_at: 1
  //     type_id: sensor_slidingwindowmovingaveragefilter
  //   - heartbeat: 200ms
  //     type_id: sensor_heartbeatfilter
  //   disabled_by_default: false
  //   force_update: false
  //   update_interval: 60s
  LD1115H_Signal = new template_::TemplateSensor();
  App.register_sensor(LD1115H_Signal);
  LD1115H_Signal->set_name("Radar Signal Strength");
  LD1115H_Signal->set_disabled_by_default(false);
  LD1115H_Signal->set_icon("mdi:signal-distance-variant");
  LD1115H_Signal->set_unit_of_measurement("");
  LD1115H_Signal->set_accuracy_decimals(0);
  LD1115H_Signal->set_force_update(false);
  sensor_slidingwindowmovingaveragefilter = new sensor::SlidingWindowMovingAverageFilter(8, 2, 1);
  sensor_heartbeatfilter = new sensor::HeartbeatFilter(200);
  sensor_heartbeatfilter->set_component_source("sensor");
  App.register_component(sensor_heartbeatfilter);
  LD1115H_Signal->set_filters({sensor_slidingwindowmovingaveragefilter, sensor_heartbeatfilter});
  LD1115H_Signal->set_update_interval(60000);
  LD1115H_Signal->set_component_source("template.sensor");
  App.register_component(LD1115H_Signal);
  // text_sensor.wifi_info:
  //   platform: wifi_info
  //   ip_address:
  //     name: Radar IP Address
  //     disabled_by_default: false
  //     id: wifi_info_ipaddresswifiinfo
  //     entity_category: diagnostic
  //     update_interval: 1s
  //   ssid:
  //     name: Radar SSID
  //     disabled_by_default: false
  //     id: wifi_info_ssidwifiinfo
  //     entity_category: diagnostic
  //     update_interval: 1s
  //   bssid:
  //     name: Radar BSSID
  //     disabled_by_default: false
  //     id: wifi_info_bssidwifiinfo
  //     entity_category: diagnostic
  //     update_interval: 1s
  //   mac_address:
  //     name: Radar Mac Address
  //     disabled_by_default: false
  //     id: wifi_info_macaddresswifiinfo
  //     entity_category: diagnostic
  wifi_info_ipaddresswifiinfo = new wifi_info::IPAddressWiFiInfo();
  App.register_text_sensor(wifi_info_ipaddresswifiinfo);
  wifi_info_ipaddresswifiinfo->set_name("Radar IP Address");
  wifi_info_ipaddresswifiinfo->set_disabled_by_default(false);
  wifi_info_ipaddresswifiinfo->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  wifi_info_ipaddresswifiinfo->set_update_interval(1000);
  wifi_info_ipaddresswifiinfo->set_component_source("wifi_info.text_sensor");
  App.register_component(wifi_info_ipaddresswifiinfo);
  wifi_info_ssidwifiinfo = new wifi_info::SSIDWiFiInfo();
  App.register_text_sensor(wifi_info_ssidwifiinfo);
  wifi_info_ssidwifiinfo->set_name("Radar SSID");
  wifi_info_ssidwifiinfo->set_disabled_by_default(false);
  wifi_info_ssidwifiinfo->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  wifi_info_ssidwifiinfo->set_update_interval(1000);
  wifi_info_ssidwifiinfo->set_component_source("wifi_info.text_sensor");
  App.register_component(wifi_info_ssidwifiinfo);
  wifi_info_bssidwifiinfo = new wifi_info::BSSIDWiFiInfo();
  App.register_text_sensor(wifi_info_bssidwifiinfo);
  wifi_info_bssidwifiinfo->set_name("Radar BSSID");
  wifi_info_bssidwifiinfo->set_disabled_by_default(false);
  wifi_info_bssidwifiinfo->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  wifi_info_bssidwifiinfo->set_update_interval(1000);
  wifi_info_bssidwifiinfo->set_component_source("wifi_info.text_sensor");
  App.register_component(wifi_info_bssidwifiinfo);
  wifi_info_macaddresswifiinfo = new wifi_info::MacAddressWifiInfo();
  App.register_text_sensor(wifi_info_macaddresswifiinfo);
  wifi_info_macaddresswifiinfo->set_name("Radar Mac Address");
  wifi_info_macaddresswifiinfo->set_disabled_by_default(false);
  wifi_info_macaddresswifiinfo->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  wifi_info_macaddresswifiinfo->set_component_source("wifi_info.text_sensor");
  App.register_component(wifi_info_macaddresswifiinfo);
  // text_sensor.serial:
  //   platform: serial
  //   uart_id: LD1115H_UART_BUS
  //   name: Radar UART Text
  //   id: LD1115H_UART_Text
  //   icon: mdi:format-text
  //   internal: true
  //   on_value:
  //   - then:
  //     - lambda: !lambda |-
  //         if (id(LD1115H_UART_Text).state.substr(0,3) == "occ") {
  //           id(LD1115H_Signal).publish_state(atof(id(LD1115H_UART_Text).state.substr(7).c_str()));
  //           id(LD1115H_Spectral).publish_state(atof(id(LD1115H_UART_Text).state.substr(5,2).c_str()));
  //           if ((time(NULL)-id(LD1115H_Last_Mov_Time))>id(LD1115H_Mov_Time).state) {
  //             id(LD1115H_Occupancy).publish_state("Occupancy");
  //             if (id(LD1115H_MovOcc_Binary).state == false) {
  //               id(LD1115H_MovOcc_Binary).publish_state(true);
  //             }
  //             if (id(LD1115H_Mov_Binary).state == true) {
  //               id(LD1115H_Mov_Binary).publish_state(false);
  //             }
  //           }
  //           if (id(LD1115H_MovOcc_Binary).state == false) {
  //             id(LD1115H_MovOcc_Binary).publish_state(true);
  //           }
  //           id(LD1115H_Last_Time) = time(NULL);
  //           if (id(LD1115H_Clearence_Status) == true) {
  //             id(LD1115H_Clearence_Status) = false;
  //           }
  //         }
  //         else if (id(LD1115H_UART_Text).state.substr(0,3) == "mov") {
  //           id(LD1115H_Signal).publish_state(atof(id(LD1115H_UART_Text).state.substr(7).c_str()));
  //           id(LD1115H_Spectral).publish_state(atof(id(LD1115H_UART_Text).state.substr(5,2).c_str()));
  //           id(LD1115H_Occupancy).publish_state("Movement");
  //           if (id(LD1115H_MovOcc_Binary).state == false) {
  //             id(LD1115H_MovOcc_Binary).publish_state(true);
  //           }
  //           if (id(LD1115H_Mov_Binary).state == false) {
  //             id(LD1115H_Mov_Binary).publish_state(true);
  //           }
  //           id(LD1115H_Last_Mov_Time) = time(NULL);
  //           id(LD1115H_Last_Time) = time(NULL);
  //           if (id(LD1115H_Clearence_Status) == true) {
  //             id(LD1115H_Clearence_Status) = false;
  //           }
  //         }
  //       type_id: lambdaaction_2
  //     automation_id: automation_5
  //     trigger_id: text_sensor_textsensorstatetrigger
  //   disabled_by_default: false
  LD1115H_UART_Text = new serial::SerialTextSensor();
  LD1115H_UART_Text->set_component_source("serial.text_sensor");
  App.register_component(LD1115H_UART_Text);
  App.register_text_sensor(LD1115H_UART_Text);
  LD1115H_UART_Text->set_name("Radar UART Text");
  LD1115H_UART_Text->set_disabled_by_default(false);
  LD1115H_UART_Text->set_internal(true);
  LD1115H_UART_Text->set_icon("mdi:format-text");
  text_sensor_textsensorstatetrigger = new text_sensor::TextSensorStateTrigger(LD1115H_UART_Text);
  automation_5 = new Automation<std::string>(text_sensor_textsensorstatetrigger);
  // text_sensor.template:
  //   platform: template
  //   name: Radar Occupancy Status
  //   id: LD1115H_Occupancy
  //   icon: mdi:motion-sensor
  //   disabled_by_default: false
  //   update_interval: 60s
  LD1115H_Occupancy = new template_::TemplateTextSensor();
  App.register_text_sensor(LD1115H_Occupancy);
  LD1115H_Occupancy->set_name("Radar Occupancy Status");
  LD1115H_Occupancy->set_disabled_by_default(false);
  LD1115H_Occupancy->set_icon("mdi:motion-sensor");
  LD1115H_Occupancy->set_update_interval(60000);
  LD1115H_Occupancy->set_component_source("template.text_sensor");
  App.register_component(LD1115H_Occupancy);
  // binary_sensor.status:
  //   platform: status
  //   name: Radar Status
  //   disabled_by_default: false
  //   id: status_statusbinarysensor
  //   entity_category: diagnostic
  //   device_class: connectivity
  status_statusbinarysensor = new status::StatusBinarySensor();
  App.register_binary_sensor(status_statusbinarysensor);
  status_statusbinarysensor->set_name("Radar Status");
  status_statusbinarysensor->set_disabled_by_default(false);
  status_statusbinarysensor->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  status_statusbinarysensor->set_device_class("connectivity");
  status_statusbinarysensor->set_component_source("status.binary_sensor");
  App.register_component(status_statusbinarysensor);
  // binary_sensor.template:
  //   platform: template
  //   name: Radar Occupancy or Movement
  //   id: LD1115H_MovOcc_Binary
  //   device_class: occupancy
  //   on_state:
  //   - then:
  //     - binary_sensor.template.publish:
  //         id: Unified_Presence
  //         state: !lambda |-
  //           if (id(LD1115H_Mov_Binary).state || id(pir_sensor).state) {
  //             return true;
  //           } else {
  //             return false;
  //           }
  //       type_id: binary_sensor_binarysensorpublishaction
  //     automation_id: automation_6
  //     trigger_id: binary_sensor_statetrigger
  //   disabled_by_default: false
  LD1115H_MovOcc_Binary = new template_::TemplateBinarySensor();
  App.register_binary_sensor(LD1115H_MovOcc_Binary);
  LD1115H_MovOcc_Binary->set_name("Radar Occupancy or Movement");
  LD1115H_MovOcc_Binary->set_disabled_by_default(false);
  LD1115H_MovOcc_Binary->set_device_class("occupancy");
  binary_sensor_statetrigger = new binary_sensor::StateTrigger(LD1115H_MovOcc_Binary);
  automation_6 = new Automation<bool>(binary_sensor_statetrigger);
  // binary_sensor.template:
  //   platform: template
  //   name: Radar Movement
  //   id: LD1115H_Mov_Binary
  //   device_class: motion
  //   disabled_by_default: false
  LD1115H_Mov_Binary = new template_::TemplateBinarySensor();
  App.register_binary_sensor(LD1115H_Mov_Binary);
  LD1115H_Mov_Binary->set_name("Radar Movement");
  LD1115H_Mov_Binary->set_disabled_by_default(false);
  LD1115H_Mov_Binary->set_device_class("motion");
  LD1115H_Mov_Binary->set_component_source("template.binary_sensor");
  App.register_component(LD1115H_Mov_Binary);
  // binary_sensor.gpio:
  //   platform: gpio
  //   pin:
  //     number: 19
  //     mode:
  //       input: true
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     inverted: false
  //     id: esp32_esp32internalgpiopin_4
  //     drive_strength: 20.0
  //   name: PIR Sensor
  //   id: pir_sensor
  //   device_class: motion
  //   on_state:
  //   - then:
  //     - binary_sensor.template.publish:
  //         id: Unified_Presence
  //         state: !lambda |-
  //           if (id(LD1115H_Mov_Binary).state || id(pir_sensor).state) {
  //             return true;
  //           } else {
  //             return false;
  //           }
  //       type_id: binary_sensor_binarysensorpublishaction_2
  //     automation_id: automation_7
  //     trigger_id: binary_sensor_statetrigger_2
  //   disabled_by_default: false
  pir_sensor = new gpio::GPIOBinarySensor();
  App.register_binary_sensor(pir_sensor);
  pir_sensor->set_name("PIR Sensor");
  pir_sensor->set_disabled_by_default(false);
  pir_sensor->set_device_class("motion");
  binary_sensor_statetrigger_2 = new binary_sensor::StateTrigger(pir_sensor);
  automation_7 = new Automation<bool>(binary_sensor_statetrigger_2);
  // binary_sensor.template:
  //   platform: template
  //   id: Unified_Presence
  //   name: Presence Sensor
  //   on_state:
  //   - then:
  //     - delay: !lambda |-
  //         if(!(id(LD1115H_Mov_Binary).state || id(pir_sensor).state))
  //         {
  //           return id(presence_delay_off).state * 1000;
  //         }
  //         else
  //         {
  //           return 0;
  //         }
  //       type_id: delayaction
  //     - binary_sensor.template.publish:
  //         id: Unified_Presence
  //         state: !lambda |-
  //           if (id(LD1115H_Mov_Binary).state || id(pir_sensor).state) {
  //             return true;
  //           } else {
  //             return false;
  //           }
  //       type_id: binary_sensor_binarysensorpublishaction_3
  //     automation_id: automation_8
  //     trigger_id: binary_sensor_statetrigger_3
  //   disabled_by_default: false
  Unified_Presence = new template_::TemplateBinarySensor();
  App.register_binary_sensor(Unified_Presence);
  Unified_Presence->set_name("Presence Sensor");
  Unified_Presence->set_disabled_by_default(false);
  binary_sensor_statetrigger_3 = new binary_sensor::StateTrigger(Unified_Presence);
  automation_8 = new Automation<bool>(binary_sensor_statetrigger_3);
  delayaction = new DelayAction<bool>();
  delayaction->set_component_source("binary_sensor");
  App.register_component(delayaction);
  delayaction->set_delay([=](bool x) -> uint32_t {
      #line 320 "/config/esphome/lab-module.yaml"
      if(!(LD1115H_Mov_Binary->state || pir_sensor->state))
      {
        return presence_delay_off->state * 1000;
      }
      else
      {
        return 0;
      }
  });
  binary_sensor_binarysensorpublishaction_3 = new binary_sensor::BinarySensorPublishAction<bool>(Unified_Presence);
  binary_sensor_binarysensorpublishaction_3->set_state([=](bool x) -> bool {
      #line 331 "/config/esphome/lab-module.yaml"
      if (LD1115H_Mov_Binary->state || pir_sensor->state) {
        return true;
      } else {
        return false;
      }
  });
  automation_8->add_actions({delayaction, binary_sensor_binarysensorpublishaction_3});
  Unified_Presence->set_component_source("template.binary_sensor");
  App.register_component(Unified_Presence);
  // socket:
  //   implementation: bsd_sockets
  // network:
  //   {}
  uart_uartwriteaction->set_parent(LD1115H_UART_BUS);
  uart_uartwriteaction->set_data_template([=]() -> std::vector<uint8_t> {
      #line 14 "/config/esphome/lab-module.yaml"
      std::string th1st = "th1=" + str_sprintf("%.0f",LD1115H_TH1->state) +" \n";
      return std::vector<uint8_t>(th1st.begin(), th1st.end());
  });
  uart_uartwriteaction_2 = new uart::UARTWriteAction<>();
  uart_uartwriteaction_2->set_parent(LD1115H_UART_BUS);
  uart_uartwriteaction_2->set_data_template([=]() -> std::vector<uint8_t> {
      #line 19 "/config/esphome/lab-module.yaml"
      std::string th2st = "th2=" + str_sprintf("%.0f",LD1115H_TH2->state) +" \n";
      return std::vector<uint8_t>(th2st.begin(), th2st.end());
  });
  automation->add_actions({uart_uartwriteaction, uart_uartwriteaction_2});
  binary_sensor_binarysensorpublishaction = new binary_sensor::BinarySensorPublishAction<bool>(Unified_Presence);
  binary_sensor_binarysensorpublishaction->set_state([=](bool x) -> bool {
      #line 284 "/config/esphome/lab-module.yaml"
      if (LD1115H_Mov_Binary->state || pir_sensor->state) {
        return true;
      } else {
        return false;
      }
  });
  automation_6->add_actions({binary_sensor_binarysensorpublishaction});
  LD1115H_MovOcc_Binary->set_component_source("template.binary_sensor");
  App.register_component(LD1115H_MovOcc_Binary);
  binary_sensor_binarysensorpublishaction_2 = new binary_sensor::BinarySensorPublishAction<bool>(Unified_Presence);
  binary_sensor_binarysensorpublishaction_2->set_state([=](bool x) -> bool {
      #line 303 "/config/esphome/lab-module.yaml"
      if (LD1115H_Mov_Binary->state || pir_sensor->state) {
        return true;
      } else {
        return false;
      }
  });
  automation_7->add_actions({binary_sensor_binarysensorpublishaction_2});
  pir_sensor->set_component_source("gpio.binary_sensor");
  App.register_component(pir_sensor);
  esp32_esp32internalgpiopin_4 = new esp32::ESP32InternalGPIOPin();
  esp32_esp32internalgpiopin_4->set_pin(::GPIO_NUM_19);
  esp32_esp32internalgpiopin_4->set_inverted(false);
  esp32_esp32internalgpiopin_4->set_drive_strength(::GPIO_DRIVE_CAP_2);
  esp32_esp32internalgpiopin_4->set_flags(gpio::Flags::FLAG_INPUT);
  pir_sensor->set_pin(esp32_esp32internalgpiopin_4);
  // globals:
  //   id: LD1115H_Last_Time
  //   type: time_t
  //   restore_value: false
  //   initial_value: time(NULL)
  LD1115H_Last_Time = new globals::GlobalsComponent<time_t>(time(NULL));
  LD1115H_Last_Time->set_component_source("globals");
  App.register_component(LD1115H_Last_Time);
  // globals:
  //   id: LD1115H_Last_Mov_Time
  //   type: time_t
  //   restore_value: false
  //   initial_value: time(NULL)
  LD1115H_Last_Mov_Time = new globals::GlobalsComponent<time_t>(time(NULL));
  LD1115H_Last_Mov_Time->set_component_source("globals");
  App.register_component(LD1115H_Last_Mov_Time);
  // globals:
  //   id: LD1115H_Clearence_Status
  //   type: bool
  //   restore_value: false
  //   initial_value: 'false'
  LD1115H_Clearence_Status = new globals::GlobalsComponent<bool>(false);
  LD1115H_Clearence_Status->set_component_source("globals");
  App.register_component(LD1115H_Clearence_Status);
  lambdaaction = new LambdaAction<>([=]() -> void {
      #line 110 "/config/esphome/lab-module.yaml"
      if ((time(NULL)-LD1115H_Last_Time->value())>LD1115H_Clear_Time->state) {
        if ((LD1115H_Clearence_Status->value() == false) || (LD1115H_Occupancy->state != "Clearance")) {
          LD1115H_Occupancy->publish_state("Clearance");
          LD1115H_Clearence_Status->value() = true;
        }
        if (LD1115H_MovOcc_Binary->state == true) {
          LD1115H_MovOcc_Binary->publish_state(false);
        }
        if (LD1115H_Mov_Binary->state == true) {
          LD1115H_Mov_Binary->publish_state(false);
        }
      }
  });
  automation_2->add_actions({lambdaaction});
  interval_intervaltrigger->set_update_interval(1000);
  lambdaaction_2 = new LambdaAction<std::string>([=](std::string x) -> void {
      #line 232 "/config/esphome/lab-module.yaml"
      if (LD1115H_UART_Text->state.substr(0,3) == "occ") {
        LD1115H_Signal->publish_state(atof(LD1115H_UART_Text->state.substr(7).c_str()));
        LD1115H_Spectral->publish_state(atof(LD1115H_UART_Text->state.substr(5,2).c_str()));
        if ((time(NULL)-LD1115H_Last_Mov_Time->value())>LD1115H_Mov_Time->state) {
          LD1115H_Occupancy->publish_state("Occupancy");
          if (LD1115H_MovOcc_Binary->state == false) {
            LD1115H_MovOcc_Binary->publish_state(true);
          }
          if (LD1115H_Mov_Binary->state == true) {
            LD1115H_Mov_Binary->publish_state(false);
          }
        }
        if (LD1115H_MovOcc_Binary->state == false) {
          LD1115H_MovOcc_Binary->publish_state(true);
        }
        LD1115H_Last_Time->value() = time(NULL);
        if (LD1115H_Clearence_Status->value() == true) {
          LD1115H_Clearence_Status->value() = false;
        }
      }
      else if (LD1115H_UART_Text->state.substr(0,3) == "mov") {
        LD1115H_Signal->publish_state(atof(LD1115H_UART_Text->state.substr(7).c_str()));
        LD1115H_Spectral->publish_state(atof(LD1115H_UART_Text->state.substr(5,2).c_str()));
        LD1115H_Occupancy->publish_state("Movement");
        if (LD1115H_MovOcc_Binary->state == false) {
          LD1115H_MovOcc_Binary->publish_state(true);
        }
        if (LD1115H_Mov_Binary->state == false) {
          LD1115H_Mov_Binary->publish_state(true);
        }
        LD1115H_Last_Mov_Time->value() = time(NULL);
        LD1115H_Last_Time->value() = time(NULL);
        if (LD1115H_Clearence_Status->value() == true) {
          LD1115H_Clearence_Status->value() = false;
        }
      }
  });
  automation_5->add_actions({lambdaaction_2});
  LD1115H_UART_Text->set_uart_parent(LD1115H_UART_BUS);
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop() {
  App.loop();
}
