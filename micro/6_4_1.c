/*プログラムを起動すると赤色のLED は消灯している．赤色の押しボタンスイッチSW を押すと
赤色のLED が薄暗く点灯，黒色の押しボタンスイッチSW を押すと赤色のLED が明るく点灯す
るプログラムを作成して実行する．*/

int LED2 = 10; // LED赤
int SW1 = 12; // スイッチ黒
int BRIGHT = 250; // 明るい
int DARK = 100; // 明るい
void setup()
{
    pinMode(SW1, INPUT);
}
void loop()
{
    if(digitalRead(SW1) == HIGH) {
        analogWrite(LED2, DARK);
    } else {
        analogWrite(LED2, BRIGHT);
    }
}