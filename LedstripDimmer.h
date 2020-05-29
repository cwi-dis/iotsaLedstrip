#ifndef _LEDSTRIPDIMMER_H_
#define _LEDSTRIPDIMMER_H_
#include "iotsa.h"
#include "AbstractDimmer.h"
#include "iotsaPixelstrip.h"

#include "NPBColorLib.h"

namespace Lissabon {

class LedstripDimmer : public AbstractDimmer, public IotsaPixelsource {
public:
  LedstripDimmer(int _num, IotsaPixelstripMod& _mod, DimmerCallbacks *_callbacks);
  void setup();
  void updateDimmer();
  bool available();
  void identify();
  void loop();
  // Overrides
  virtual bool getHandler(JsonObject& reply) override;
  virtual bool putHandler(const JsonVariant& request) override;
  virtual bool putConfigHandler(const JsonVariant& request) override;
  virtual bool handlerArgs(IotsaWebServer *server) override;
  virtual bool handlerConfigArgs(IotsaWebServer *server) override;
  virtual void configLoad(IotsaConfigFileLoad& cf) override;
  virtual void configSave(IotsaConfigFileSave& cf) override;
  virtual String handlerForm() override;
  virtual String handlerConfigForm() override;

  void setHandler(uint8_t *_buffer, size_t _count, int bpp, IotsaPixelsourceHandler *handler);
protected:
  IotsaPixelstripMod& mod;
  float prevLevel;
  uint32_t millisAnimationStart;
  uint32_t millisAnimationEnd;
  uint8_t *buffer;
  int count;  // Number of LEDs
  int bpp; // Number of colors per LED (3 or 4)
  IotsaPixelsourceHandler *stripHandler;

  TempFColor tempColor;
  Colorspace rgbwSpace;

  RgbwColor color;
  RgbwColor prevColor;

};
};
#endif // _LEDSTRIPDIMMER_H_