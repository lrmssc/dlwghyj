////  ShopScene.cpp//  dianliwangguomanyouji////  Created by szsycx on 3/17/15.////#include "ShopScene.h"#include "LevelScene.h"Scene* ShopScene::createScene(){    Scene * scene= Scene::create();    Layer * layer = ShopScene::create();    scene->addChild(layer);    return scene;}bool ShopScene::init(){    if(!Layer::init()){        return false;    }    Size visibleSize = Director::getInstance()->getVisibleSize();        CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("shop.mp3");    bool isMusicPlay = UserDefault::getInstance()->getBoolForKey("music", true);    if(isMusicPlay){        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("shop.mp3",true);    }    auto bg = Sprite::create("shop/bg.jpg");    bg->setPosition(Vec2(visibleSize.width/2.0,visibleSize.height/2.0));    addChild(bg);        beanNumber = UserDefault::getInstance()->getIntegerForKey("bean");    item1Number = UserDefault::getInstance()->getIntegerForKey("item1");    item2Number = UserDefault::getInstance()->getIntegerForKey("item2");    item3Number = UserDefault::getInstance()->getIntegerForKey("item3");    item4Number = UserDefault::getInstance()->getIntegerForKey("item4");        auto dbg = Sprite::create("shop/dbg.png");    dbg->setPosition(Vec2(visibleSize.width-dbg->getContentSize().width/2.0-1,visibleSize.height-dbg->getContentSize().height/2.0-1));    addChild(dbg);                    item1n = Text::create(StringUtils::format("%d",item1Number), "", 42);    item1n->setPosition(Vec2(visibleSize.width*6.6/10.0,visibleSize.height*9.41/10.0));    addChild(item1n);        item2n = Text::create(StringUtils::format("%d",item2Number), "", 42);    item2n->setPosition(Vec2(visibleSize.width*5.0/10.0,visibleSize.height*9.41/10.0));    addChild(item2n);        item3n = Text::create(StringUtils::format("%d",item3Number), "", 42);    item3n->setPosition(Vec2(visibleSize.width*8.0/10.0,visibleSize.height*9.41/10.0));    addChild(item3n);        item4n = Text::create(StringUtils::format("%d",item4Number), "", 42);    item4n->setPosition(Vec2(visibleSize.width*9.5/10.0,visibleSize.height*9.41/10.0));    addChild(item4n);        bean = Text::create(StringUtils::format("%d",beanNumber), "", 50);    bean->setPosition(Vec2(visibleSize.width*8.5/10.0,visibleSize.height*0.8/10.0));    addChild(bean);            auto back = Button::create("shop/back.png");    back->addTouchEventListener([](Ref*pSender ,Widget::TouchEventType type){        if(type==Widget::TouchEventType::ENDED){           bool  isPlayMusic = UserDefault::getInstance()->getBoolForKey("music", true);            if(isPlayMusic){                CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();                CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("xuqu.mp3");                CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("xuqu.mp3", true);            }            Director::getInstance()->replaceScene(LevelScene::createScene());        }    });    back->setPosition(Vec2(back->getContentSize().width/2.0,back->getContentSize().height/2.0));    addChild(back);        item1 = Button::create("shop/d1.png");    item1->addTouchEventListener([&](Ref*pSender ,Widget::TouchEventType type){        if(type==Widget::TouchEventType::ENDED){            if(beanNumber>=20 && item1Number<99){                currentItem=1;                yes->setVisible(true);                            }else{                        }            item1->setTouchEnabled(false);            item2->setTouchEnabled(false);            item3->setTouchEnabled(false);            item4->setTouchEnabled(false);                        dbg1->setVisible(true);            no->setVisible(true);        }    });    item1->setPosition(Vec2(visibleSize.width*5.6/10.0,visibleSize.height*6.0/10.0));    addChild(item1);            item2 = Button::create("shop/d2.png");    item2->addTouchEventListener([&](Ref*pSender ,Widget::TouchEventType type){        if(type==Widget::TouchEventType::ENDED){            if(beanNumber>=10&&item2Number<99){                currentItem=2;                yes->setVisible(true);                            }else{                            }            item1->setTouchEnabled(false);            item2->setTouchEnabled(false);            item3->setTouchEnabled(false);            item4->setTouchEnabled(false);                        dbg2->setVisible(true);            no->setVisible(true);        }    });    item2->setPosition(Vec2(visibleSize.width*4.0/10.0,visibleSize.height*6.0/10.0));    addChild(item2);        item3 = Button::create("shop/d3.png");    item3->addTouchEventListener([&](Ref*pSender ,Widget::TouchEventType type){        if(type==Widget::TouchEventType::ENDED){            if(beanNumber>=40&&item3Number<99){                currentItem=3;                yes->setVisible(true);                            }else{                            }            item1->setTouchEnabled(false);            item2->setTouchEnabled(false);            item3->setTouchEnabled(false);            item4->setTouchEnabled(false);                        dbg3->setVisible(true);            no->setVisible(true);        }    });    item3->setPosition(Vec2(visibleSize.width*7.3/10.0,visibleSize.height*6.0/10.0));    addChild(item3);            item4 = Button::create("shop/d4.png");    item4->addTouchEventListener([&](Ref*pSender ,Widget::TouchEventType type){        if(type==Widget::TouchEventType::ENDED){            if(beanNumber>=60 && item4Number<99){                currentItem=4;                yes->setVisible(true);                            }else{                            }            item1->setTouchEnabled(false);            item2->setTouchEnabled(false);            item3->setTouchEnabled(false);            item4->setTouchEnabled(false);                        dbg4->setVisible(true);            no->setVisible(true);        }    });    item4->setPosition(Vec2(visibleSize.width*9.0/10.0,visibleSize.height*6.0/10.0));    addChild(item4);            dbg1 = Sprite::create("shop/dbg1.png");    dbg1->setPosition(Vec2(visibleSize.width*2.0/3.0,visibleSize.height/2.0));    addChild(dbg1);        dbg2 = Sprite::create("shop/dbg2.png");    dbg2->setPosition(dbg1->getPosition());    addChild(dbg2);        dbg3 = Sprite::create("shop/dbg3.png");    dbg3->setPosition(dbg1->getPosition());    addChild(dbg3);        dbg4 = Sprite::create("shop/dbg4.png");    dbg4->setPosition(dbg1->getPosition());    addChild(dbg4);        yes = Button::create("shop/yes.png");    yes->addTouchEventListener([&](Ref*pSender ,Widget::TouchEventType type){        if(type==Widget::TouchEventType::ENDED){            if(beanNumber>0){                switch(currentItem){                    case 1:                                                 beanNumber-=20;                        item1Number++;                        item1n->setString(StringUtils::format("%d",item1Number).c_str());                        UserDefault::getInstance()->setIntegerForKey("item1", item1Number);                        break;                    case 2:                        beanNumber-=10;                        item2Number++;                        item2n->setString(StringUtils::format("%d",item2Number).c_str());                        UserDefault::getInstance()->setIntegerForKey("item2", item2Number);                        break;                    case 3:                        beanNumber-=40;                        item3Number++;                        item3n->setString(StringUtils::format("%d",item3Number).c_str());                        UserDefault::getInstance()->setIntegerForKey("item3", item3Number);                        break;                    case 4:                        beanNumber-=60;                        item4Number++;                        item4n->setString(StringUtils::format("%d",item4Number).c_str());                        UserDefault::getInstance()->setIntegerForKey("item4", item4Number);                        break;                }                UserDefault::getInstance()->setIntegerForKey("bean", beanNumber);                bean->setText(StringUtils::format("%d",beanNumber).c_str());                UserDefault::getInstance()->flush();            }            yes->setVisible(false);            no->setVisible(false);            dbg1->setVisible(false);            dbg2->setVisible(false);            dbg3->setVisible(false);            dbg4->setVisible(false);            item1->setTouchEnabled(true);            item2->setTouchEnabled(true);            item3->setTouchEnabled(true);            item4->setTouchEnabled(true);                    }    });    yes->setPosition(Vec2(visibleSize.width/2.0+yes->getContentSize().width/2.0, visibleSize.height/4.0));    addChild(yes);        no = Button::create("shop/no.png");    no->addTouchEventListener([&](Ref*pSender ,Widget::TouchEventType type){        if(type==Widget::TouchEventType::ENDED){            no->setVisible(false);            yes->setVisible(false);            dbg1->setVisible(false);            dbg2->setVisible(false);            dbg3->setVisible(false);            dbg4->setVisible(false);            item1->setTouchEnabled(true);            item2->setTouchEnabled(true);            item3->setTouchEnabled(true);            item4->setTouchEnabled(true);        }    });    no->setPosition(Vec2(visibleSize.width*8.0/10.0, visibleSize.height/4.0));    addChild(no);        dbg1->setVisible(false);    dbg2->setVisible(false);    dbg3->setVisible(false);    dbg4->setVisible(false);    yes->setVisible(false);    no->setVisible(false);        return true;}