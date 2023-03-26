#include "esphome.h"
#include <string>

class hilink : public Component, public UARTDevice {
 public:
  hilink(UARTComponent *parent) : UARTDevice(parent) {}
  Sensor *mov_SNR = new Sensor();
  Sensor *occ_SNR = new Sensor();
  void setup() override {
    //
  }

  void getmmwConf(std::string mmwparam) {
    mmwparam = mmwparam + "\n";
    write_array(std::vector<unsigned char>(mmwparam.begin(), mmwparam.end()));
  }

  int readline(int readch, char *buffer, int len)
  {
    static int pos = 0;
    int rpos;

    if (readch > 0) {
      switch (readch) {
        case '\n': // Ignore new-lines
          break;
        case '\r': // Return on new-lines
          rpos = pos;
          pos = 0;  // Reset position index ready for next time
          return rpos;
        default:
          if (pos < len-1) {
            buffer[pos++] = readch;
            buffer[pos] = 0;
          }
      }
    }
    // No end of line has been found, so return -1.
    return -1;
  }

  void loop() override {
    const int max_line_length = 80;
    static char buffer[max_line_length];

    while (available()) {
      if(readline(read(), buffer, max_line_length) > 0) {
        std::string line = buffer;

        //ESP_LOGD("custom", "Line is: %s", line.c_str());
        if (line.substr(0,3) == "th1") {
          ESP_LOGD("custom", "Found th1: %s", line.c_str());
          id(mov_SNR_target).publish_state(parse_number<int>(line.substr(7)).value());
        }
        else if (line.substr(0,3) == "th2") {
          ESP_LOGD("custom", "Found th2: %s", line.c_str());
          id(occ_SNR_target).publish_state(parse_number<int>(line.substr(7)).value());
        }
        else if (line.substr(0,3) == "th3") {
          ESP_LOGD("custom", "Found th3: %s", line.c_str());
          id(th3_SNR_target).publish_state(parse_number<int>(line.substr(7)).value());
        }
        else if (line.substr(0,7) == "ind_min") {
          ESP_LOGD("custom", "Found ind_min: %s", line.c_str());
          id(ind_min).publish_state(parse_number<int>(line.substr(11)).value());
        }
        else if (line.substr(0,7) == "ind_max") {
          ESP_LOGD("custom", "Found ind_max: %s", line.c_str());
          id(ind_max).publish_state(parse_number<int>(line.substr(11)).value());
        }
        else if (line.substr(0,6) == "mov_sn") {
          ESP_LOGD("custom", "Found mov_sn: %s", line.c_str());
          id(mov_sn).publish_state(parse_number<int>(line.substr(10)).value());
        }
        else if (line.substr(0,6) == "occ_sn") {
          ESP_LOGD("custom", "Found occ_sn: %s", line.c_str());
          id(occ_sn).publish_state(parse_number<int>(line.substr(10)).value());
        }
        else if (line.substr(0,5) == "dtime") {
          ESP_LOGD("custom", "Found dtime: '%s'", line.c_str());
          std::string dtime_str = line.substr(9,(line.length() - 12));
          int dtime_ms = parse_number<int>(dtime_str).value();
          ESP_LOGD("custom", "Found dtime_ms: %i", dtime_ms);
          id(dtime).publish_state(dtime_ms/1000);
        }
        if (line.substr(0,4) == "mov," && id(show_SNR).state) {
          // ESP_LOGD("custom", "Found occ_sn: %s", line.c_str());
          mov_SNR->publish_state(parse_number<int>(line.substr(7)).value());
        }
        else if (line.substr(0,4) == "occ," && id(show_SNR).state) {
          // ESP_LOGD("custom", "Found occ_sn: %s", line.c_str());
          occ_SNR->publish_state(parse_number<int>(line.substr(7)).value());
        }
      }
    }
  }
};