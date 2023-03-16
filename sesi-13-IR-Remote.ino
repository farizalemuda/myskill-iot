#include <IRremote.h>
#include <LiquidCrystal.h>

#define PIN_RECEIVER 2   // Signal Pin of IR receiver

IRrecv receiver(PIN_RECEIVER);

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup()
{
  lcd.begin(16, 2);
  lcd.print("<press a button>");
  receiver.enableIRIn(); // Start the receiver
}

void loop()
{
  // Checks received an IR signal
  if (receiver.decode()) {
    translateIR();
    receiver.resume();  // Receive the next value
  }
}

void lcdPrint(char* text)
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("button pressed:");
  lcd.setCursor(0, 1);
  lcd.print(text);
  lcd.print(" code: ");
  lcd.print(receiver.decodedIRData.command);
}

void translateIR()
{
  // Takes command based on IR code received
  switch (receiver.decodedIRData.command) {
    case 162:
      lcdPrint("POWER");
      break;
    case 226:
      lcdPrint("MENU");
      break;
    case 34:
      lcdPrint("TEST");
      break;
    case 2:
      lcdPrint("PLUS");
      break;
    case 194:
      lcdPrint("BACK");
      break;
    case 224:
      lcdPrint("PREV.");
      break;
    case 168:
      lcdPrint("PLAY");
      break;
    case 144:
      lcdPrint("NEXT");
      break;
    case 104:
      lcdPrint("num: 0");
      break;
    case 152:
      lcdPrint("MINUS");
      break;
    case 176:
      lcdPrint("key: C");
      break;
    case 48:
      lcdPrint("num: 1");
      break;
    case 24:
      lcdPrint("num: 2");
      break;
    case 122:
      lcdPrint("num: 3");
      break;
    case 16:
      lcdPrint("num: 4");
      break;
    case 56:
      lcdPrint("num: 5");
      break;
    case 90:
      lcdPrint("num: 6");
      break;
    case 66:
      lcdPrint("num: 7");
      break;
    case 74:
      lcdPrint("num: 8");
      break;
    case 82:
      lcdPrint("num: 9");
      break;
    default:
      lcd.clear();
      lcd.print(receiver.decodedIRData.command);
      lcd.print(" other button");
  }
}
