#include "BackgroundPanel.h"
USING_NS_CC;
USING_NS_CC_EXT;


BackgroundPanel::BackgroundPanel()
{

}


BackgroundPanel::~BackgroundPanel()
{

}

const char* darkpanelpngs[] = {
   //   "ninjasprite.png"
      "lightsout-1-gray.png"
};

const char* lightpanelpngs[] = {
   "lightsout-1-color.png"
};

void BackgroundPanel::toggle()
{
   m_bLightOn = !m_bLightOn;
   // flip tex
   const char** namelist = m_bLightOn ? lightpanelpngs : darkpanelpngs;
   CCTexture2D* tex = CCTextureCache::sharedTextureCache()->addImage(namelist[0]);
   setTexture(tex);

   //CCSize texsize = tex->getContentSize();
   //CCLog("updategs width  %f %f", texsize.width, texsize.height);
   /*
   panel->setContentSize(texsize);
   panel->setColor(ccc3(255,255,255));
   panel->setVisible(true);
   */
}


BackgroundPanel* BackgroundPanel::createHack()
{
   BackgroundPanel* panel = new BackgroundPanel;
   if (panel && panel->initWithFile(darkpanelpngs[0])) {
      panel->autorelease();
      return panel;
   }
   CC_SAFE_DELETE(panel);
   return panel;
}