#include "espServer.h"

//-----------------------------------------------------------------------------

bool isConfigIP = false;

const char *wifiName = "OSV_Server";
const char *wifiPass = "OSV_Server";

IPAddress ip(172, 16, 8, 23);  //статический IP
IPAddress gateway(172, 16, 8, 1);
IPAddress subnet(255, 255, 255, 0);

String host = "http://";

uint16_t countRequest = 0;

String serverName = "";
int serverPort = 80;
  
WebServer server(serverPort);  //Define server object

#if defined(SEND_SIMPLE_RANDOM)
StaticJsonDocument<64> jsonBuffer;
#endif  //SEND_SIMPLE_RANDOM

#if defined(SEND_SITE_ON_BUTTON)
//StaticJsonDocument<64> jsonBuffer;
DynamicJsonDocument jsonBuffer(2048);
#endif  //SEND_SITE_ON_BUTTON


//-----------------------------------------------------------------------------

void generateJsonBufAntTX(String jsonKey, int jsonVal)
{
  String webPage;

  jsonBuffer[jsonKey] = jsonVal; //Put Sensor value

  serializeJson(jsonBuffer, webPage);  //Store JSON in String variable

  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Max-Age", "1000");
  server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS, DELETE, PUT");
  server.sendHeader("Access-Control-Allow-Headers", "Origin, Content-Type, Accept, Authorization, X-Request-With, X-CLIENT-ID, X-CLIENT-SECRET");
  server.sendHeader("Access-Control-Allow-Credentials:", "true");

  server.send(200, "text/html", webPage);

  Serial.println(webPage);
}

//-----------------------------------------------------------------------------

JsonObject receiveMessageFromClient(void)
{
  String message = "Number of args received:";
  String jsonmessage;
  message += server.args();      // получить количество параметров
  message += "\n";               // переход на новую строку

  for (int i = 0; i < server.args(); i++) 
  {
    message += "Arg nº" + (String)i + " –> "; // добавить текущее значение счетчика
    message += server.argName(i) + ": ";      // получить имя параметра
    message += server.arg(i) + "\n";          // получить значение параметра
    jsonmessage = server.arg(i);
  } 
  //Serial.println(message);
  Serial.println("rx String message : " + jsonmessage);
  deserializeJson(jsonBuffer, jsonmessage);

  return jsonBuffer.as<JsonObject>();
}

//-----------------------------------------------------------------------------
//Handles http request

void handlerButtonRecipe(void)
{
  String webPage;
  JsonObject objJSON = receiveMessageFromClient();
  
  jsonBuffer.clear();

#if defined(SEND_SIMPLE_RANDOM)
  jsonBuffer["buttonRecipes"] = random(-1000, 1000); //Put Sensor value
#endif  //SEND_SIMPLE_RANDOM

#if defined(SEND_SITE_ON_BUTTON)
  jsonBuffer["buttonRecipes"] = startWebPageRecipe;
#endif  //SEND_SITE_ON_BUTTON

  serializeJson(jsonBuffer, webPage);

  server.send(200, "application/json", webPage);

  Serial.print("tx JSON : ");
  Serial.println(webPage);

  digitalWrite(GPIO_DEBUGGING, digitalRead(GPIO_DEBUGGING) ^ 1);
}

//-----------------------------------------------------------------------------

void handlerButtonFastRun(void)
{
  String webPage;
  JsonObject objJSON = receiveMessageFromClient();
  
  jsonBuffer.clear();

#if defined(SEND_SIMPLE_RANDOM)
  jsonBuffer["buttonFastRun"] = random(-1000, 1000); //Put Sensor value
#endif  //SEND_SIMPLE_RANDOM

#if defined(SEND_SITE_ON_BUTTON)
  jsonBuffer["buttonFastRun"] = startWebPageFastRun;
#endif  //SEND_SITE_ON_BUTTON

  serializeJson(jsonBuffer, webPage);

  server.send(200, "application/json", webPage);

  Serial.print("tx JSON : ");
  Serial.println(webPage);

  digitalWrite(GPIO_DEBUGGING, digitalRead(GPIO_DEBUGGING) ^ 1);
}

//-----------------------------------------------------------------------------

void handlerButtonProgs(void)
{
  String webPage;
  JsonObject objJSON = receiveMessageFromClient();
  
  jsonBuffer.clear();

#if defined(SEND_SIMPLE_RANDOM)
  jsonBuffer["buttonProgs"] = random(-1000, 1000); //Put Sensor value
#endif  //SEND_SIMPLE_RANDOM

#if defined(SEND_SITE_ON_BUTTON)
  jsonBuffer["buttonProgs"] = startWebPageProgs;
#endif  //SEND_SITE_ON_BUTTON

  serializeJson(jsonBuffer, webPage);

  server.send(200, "application/json", webPage);

  Serial.print("tx JSON : ");
  Serial.println(webPage);

  digitalWrite(GPIO_DEBUGGING, digitalRead(GPIO_DEBUGGING) ^ 1);
}

//-----------------------------------------------------------------------------

void handleNotFound(void)
{
    if (server.method() == HTTP_OPTIONS)
    {
        // server.sendHeader("Access-Control-Allow-Origin", "*");
        // server.sendHeader("Access-Control-Max-Age", "10000");
        // server.sendHeader("Access-Control-Allow-Methods", "PUT,POST,GET,OPTIONS");
        // server.sendHeader("Access-Control-Allow-Headers", "*");
        server.send(204);
    }
    else
    {
        server.send(404, "text/plain", "");
    }
}

// Define routing
void restServerRouting(void)
{
  server.on("/", []()
  {
    digitalWrite(GPIO_DEBUGGING, 1);
    
    server.send(200, "text/html", startWebPage);
  });
}

//-----------------------------------------------------------------------------

void initMyServerESP32(void)
{

  Serial.begin(115200);
  delay(10);
  Serial.println();
  
  Serial.print("Connecting");

  WiFi.mode(WIFI_AP_STA);

  isConfigIP = WiFi.softAPConfig(ip, gateway, subnet);

  if(isConfigIP)
  {
    Serial.println("soft AP config = true");
    WiFi.softAP(wifiName, wifiPass);
    ip = WiFi.softAPIP();
    WiFi.config(ip, gateway, subnet);
  }
  else
  {
    Serial.println("soft AP config = false");
    return;
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  serverName = WiFi.localIP().toString();
  Serial.println("IP address: ");
  Serial.println(serverName);   //You can get IP address assigned to ESP

  host += serverName;

  server.on("/recipes", handlerButtonRecipe);
  server.on("/fastrun", handlerButtonFastRun);
  server.on("/progs", handlerButtonProgs);
  server.onNotFound(handleNotFound);
  server.enableCORS(true);

  // Activate mDNS this is used to be able to connect to the server
  // with local DNS hostmane esp8266.local
  if (MDNS.begin("esp32"))
  {
    Serial.println("mDNS responder started");
  }
  else
  {
    Serial.println("mDNS responder NOT started");
  }
  // Set server routing
  restServerRouting();

  server.begin(); //Start web server
  Serial.println("HTTP server started");

  pinMode(GPIO_DEBUGGING, GPIO_MODE_OUTPUT);

  uint8_t i;

  for (i = 0; i < 10; i++)
  {
    /* code */
    digitalWrite(GPIO_DEBUGGING, digitalRead(GPIO_DEBUGGING) ^ 1);
    delay(100);
  }
  
  digitalWrite(GPIO_DEBUGGING, 0);

}

//-----------------------------------------------------------------------------