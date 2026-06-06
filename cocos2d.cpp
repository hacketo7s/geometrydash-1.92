// The functionality for non-virtual functions defined in my version of cocos2d.h

#include<cocos2d.h>

using namespace cocos2d;

HMODULE hModule = GetModuleHandleA("libcocos2d.dll");

char const* CCDictElement::getStrKey() const {
	getStrKey_t getStrKeyFunc = reinterpret_cast<getStrKey_t>(GetProcAddress(hModule, "?getStrKey@CCDictElement@cocos2d@@QBEPBDPAV12@@Z"));

	return getStrKeyFunc(this);
};


CCObject* CCArray::objectAtIndex(unsigned int index) const {
	objectAtIndex_t objectAtIndexFunc = reinterpret_cast<objectAtIndex_t>(GetProcAddress(hModule, "?objectAtIndex@CCArray@cocos2d@@QBEPAVCCObject@2@I@Z"));

	return objectAtIndexFunc(this, index);
}

CCObject* CCDictElement::getObject() const {
	getObject_t getObjectFunc = reinterpret_cast<getObject_t>(GetProcAddress(hModule, "?getObject@CCDictElement@cocos2d@@QBEPAVCCObject@2@XZ"));

	return getObjectFunc(this);
}

CCPoint CCNode::convertToWorldSpace(CCPoint const& nodePoint) {
	convertToWorldSpace_t convertToWorldSpaceFunc = reinterpret_cast<convertToWorldSpace_t>(GetProcAddress(hModule, "?convertToWorldSpace@CCNode@cocos2d@@QAE?AVCCPoint@2@ABV32@@Z"));

	return convertToWorldSpaceFunc(this, nodePoint);
}

CCRect const& CCSprite::getTextureRect() {
	getTextureRect_t getTextureRectFunc = reinterpret_cast<getTextureRect_t>(GetProcAddress(hModule, "?getTextureRect@CCSprite@cocos2d@@QAEABVCCRect@2@XZ"));

	return getTextureRectFunc(this);
}

CCRect const& CCSpriteFrame::getRect() {
	getRect_t getRectFunc = reinterpret_cast<getRect_t>(GetProcAddress(hModule, "getRect@CCSpriteFrame@cocos2d@@QAEABVCCRect@2@XZ"));
	
	return getRectFunc(this);
}

CCRect CCNode::boundingBox() {
	boundingBox_t boundingBoxFunc = reinterpret_cast<boundingBox_t>(GetProcAddress(hModule, "?boundingBox@CCNode@cocos2d@@QAE?AVCCRect@2@XZ"));

	return boundingBoxFunc(this);
}

CCScene* CCDirector::getRunningScene() {
	getRunningScene_t getRunningSceneFunc = reinterpret_cast<getRunningScene_t>(GetProcAddress(hModule, "?getRunningScene@CCDirector@cocos2d@@QAEPAVCCScene@2@XZ"));

	return getRunningSceneFunc(this);
}

CCSize CCDirector::getWinSize() {
	getWinSize_t getWinSizeFunc = reinterpret_cast<getWinSize_t>(GetProcAddress(hModule, "?getRunningScene@CCDirector@cocos2d@@QAEPAVCCScene@2@XZ"));

	return getWinSizeFunc(this);
}

CCTexture2D* CCSpriteFrame::getTexture() {
	getTexture_t getTextureFunc = reinterpret_cast<getTexture_t>(GetProcAddress(hModule, "?getTexture@CCSpriteFrame@cocos2d@@QAEPAVCCTexture2D@2@XZ"));

	return getTextureFunc(this);
}

float CCRect::getMaxX() const {
	getMaxX_t getMaxXFunction = reinterpret_cast<getMaxX_t>(GetProcAddress(hModule, "?getMaxX@CCRect@cocos2d@@QBEMXZ"));

	return getMaxXFunction(this);
}

float CCRect::getMaxY() const {
	getMaxY_t getMaxYFunction = reinterpret_cast<getMaxY_t>(GetProcAddress(hModule, "?getMaxY@CCRect@cocos2d@@QBEMXZ"));

	return getMaxYFunction(this);
}

float CCRect::getMinX() const {
	getMinX_t getMinXFunction = reinterpret_cast<getMinX_t>(GetProcAddress(hModule, "?getMinX@CCRect@cocos2d@@QBEMXZ"));

	return getMinXFunction(this);
}

float CCRect::getMinY() const {
	getMinY_t getMinYFunction = reinterpret_cast<getMinY_t>(GetProcAddress(hModule, "?getMinY@CCRect@cocos2d@@QBEMXZ"));

	return getMinYFunction(this);
}

CCDirector* CCDirector::sharedDirector() {
	sharedDirector_t sharedDirectorFunc = reinterpret_cast<sharedDirector_t>(GetProcAddress(hModule, "?sharedDirector@CCDirector@cocos2d@@SAPAV12@XZ"));

	return sharedDirectorFunc();
}

CCSpriteFrameCache* CCSpriteFrameCache::sharedSpriteFrameCache() {
	sharedSpriteFrameCache_t sharedSpriteFrameCacheFunction = reinterpret_cast<sharedSpriteFrameCache_t>(GetProcAddress(hModule, "?sharedSpriteFrameCache@CCSpriteFrameCache@cocos2d@@SAPAV12@XZ"));

	return sharedSpriteFrameCacheFunction();
}

CCTextureCache* CCTextureCache::sharedTextureCache() {
	sharedTextureCache_t sharedTextureCacheFunction = reinterpret_cast<sharedTextureCache_t>(GetProcAddress(hModule, "?sharedTextureCache@CCTextureCache@cocos2d@@SAPAV12@XZ"));

	return sharedTextureCacheFunction();
}

float CCCamera::getEyeXYZ(float* fEyeX, float* fEyeY, float* fEyeZ) {
	getEyeXYZ_t getEyeXYZFunction = reinterpret_cast<getEyeXYZ_t>(GetProcAddress(hModule, "?getEyeXYZ@CCCamera@cocos2d@@SAMPAM00@Z"));

	return getEyeXYZFunction(fEyeX, fEyeY, fEyeZ);
}

GLFWwindow* CCEGLView::getWindow() const {
	getWindow_t getWindowFunction = reinterpret_cast<getWindow_t>(GetProcAddress(hModule, "?getWindow@CCEGLView@cocos2d@@QBEPAUGLFWwindow@@XZ"));

	return getWindowFunction(this);
}
