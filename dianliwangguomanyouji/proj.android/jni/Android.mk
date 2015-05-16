LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
../../Class/AppDelegate.cpp \
../../Class/BarrierLayer.cpp \
../../Class/CastleScene.cpp \
../../Class/ContinueGameScreen.cpp \
../../Class/GamePause.cpp \
../../Class/GameScene.cpp \
../../Class/HelloWorldScene.cpp \
../../Class/LevelLose.cpp \
../../Class/LevelScene.cpp \
../../Class/LevelWin.cpp \
../../Class/MagicGame.cpp \
../../Class/MenuScene.cpp \
../../Class/SeasonWin.cpp \
../../Class/ShopScene.cpp 

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
