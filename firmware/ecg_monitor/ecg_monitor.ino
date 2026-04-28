#define ECG_PIN   A0
#define LO_PLUS   10
#define LO_MINUS  11

const unsigned long SAMPLE_INTERVAL_US = 4000;   // 250 Hz
const int DECIMATION = 5;   // smooth display

float baseline = 512.0;
float lp = 0.0;

unsigned long lastSampleTime = 0;
unsigned long sampleCount = 0;

void setup() {
  Serial.begin(115200);

  pinMode(LO_PLUS, INPUT);
  pinMode(LO_MINUS, INPUT);

  delay(1000);
}

void loop() {
  unsigned long now = micros();

  if (now - lastSampleTime >= SAMPLE_INTERVAL_US) {
    lastSampleTime += SAMPLE_INTERVAL_US;

    int raw = 0;
    int filtered = 0;

    // Lead-off detection
    if ((digitalRead(LO_PLUS) == HIGH) || (digitalRead(LO_MINUS) == HIGH)) {
      raw = 0;
      filtered = 0;
    } 
    else {
      raw = analogRead(ECG_PIN);

      // 🔹 Baseline removal (removes drift)
      baseline = 0.995 * baseline + 0.005 * raw;
      float centered = raw - baseline;

      // 🔹 Low-pass filter (noise reduction, keeps peaks)
      lp = lp + 0.04 * (centered - lp);

      // 🔹 Amplify + shift for plotting
      filtered = (int)(lp * 4.0 + 512.0);

      // Keep within ADC range
      filtered = constrain(filtered, 0, 1023);
    }

    // 🔹 Reduce data rate for smooth graph
    if (sampleCount % DECIMATION == 0) {
      Serial.print(raw);
      Serial.print(",");
      Serial.println(filtered);
    }

    sampleCount++;
  }
}