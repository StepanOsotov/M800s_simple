
#include "espServer.h"

//-----------------------------------------------------------------------------

// the setup function runs once when you press reset or power the board
void setup(void)
{
  initMyServerESP32();
}

//-----------------------------------------------------------------------------

void loop(void)
{
  //Handle Clinet requests
  server.handleClient();
}
//-----------------------------------------------------------------------------