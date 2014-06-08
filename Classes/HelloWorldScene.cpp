#include "HelloWorldScene.h"

USING_NS_CC;
using namespace cocostudio;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	if ( !Layer::init() )  
    {
        return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

	

	ui::Layout* m_LayoutGameUI = ui::Layout::create();
	m_LayoutGameUI = dynamic_cast<ui::Layout*>(GUIReader::getInstance()->widgetFromJsonFile("OpenGameUI_1.json"));
	this->addChild(m_LayoutGameUI);
	m_LayoutGameUI->setPosition(ccp(0, 0));
	
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
