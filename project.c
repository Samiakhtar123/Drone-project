#include "esp_camera.h"
#include <WiFi.h>

// Replace with your network credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

void startCameraServer();

void setup() {
  Serial.begin(115200);
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL;
  config.ledc_timer = LEDC_TIMER;
  config.pin_d0 = 5; // Adjust according to your wiring
  config.pin_d1 = 18; // Adjust according to your wiring
  config.pin_d2 = 19; // Adjust according to your wiring
  config.pin_d3 = 21; // Adjust according to your wiring
  config.pin_d4 = 36; // Adjust according to your wiring
  config.pin_d5 = 39; // Adjust according to your wiring
  config.pin_d6 = 34; // Adjust according to your wiring
  config.pin_d7 = 35; // Adjust according to your wiring
  config.pin_xclk = 0; // Adjust according to your wiring
  config.pin_pclk = 22; // Adjust according to your wiring
  config.pin_vsync = 25; // Adjust according to your wiring
  config.pin_href = 23; // Adjust according to your wiring
  config.pin_sscb_sda = 26; // Adjust according to your wiring
  config.pin_sscb_scl = 27; // Adjust according to your wiring
  config.pin_pwdn = 32; // Adjust according to your wiring
  config.pin_reset = -1; // Reset pin not used
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_SVGA;
  config.jpeg_quality = 12; // JPEG quality
  config.fb_count = 2; // Use 2 frame buffers

  // Initialize the camera
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Start the camera server
  startCameraServer();
}

void loop() {
  // Nothing to do here
}

void startCameraServer() {
  // Start the server and handle requests
}