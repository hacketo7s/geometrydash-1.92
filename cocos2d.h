/* My unecessary limited replication of cocos2d headers from trying to port cocos-explorer to 1.92 because using HJFod's headers (which the orignal
utilized) was too hard

SPECIAL THANKS TO GEODE BINDINGS
The macros at the end of the file are from HJFod's ccMacros.h
*/


#pragma once
#include <cstddef>
#include <cstdint>
#include <Windows.h>

typedef unsigned char GLubyte;

struct _ccColor3B {
    GLubyte r;
    GLubyte g;
    GLubyte b;
};

struct UT_hash_table;

struct UT_hash_handle {
    UT_hash_table* tbl;
    void* prev;
    void* next;
    UT_hash_handle* hh_prev;
    UT_hash_handle* hh_next;
    void* key;
    unsigned int keylen;
    unsigned int hashv;
};

struct UT_hash_bucket {
    UT_hash_handle* hh_head;
    unsigned int count;
    unsigned int expand_mult;
};

struct UT_hash_table {
    UT_hash_bucket* buckets;
    unsigned int num_buckets;
    unsigned int log2_num_buckets;
    unsigned int num_items;
    UT_hash_handle* tail;
    std::ptrdiff_t hho;
    unsigned int ideal_chain_maxlen;
    unsigned int nonideal_items;
    unsigned int ineff_expands;
    unsigned int noexpand;
    std::uint32_t signature;
};

typedef struct GLFWwindow GLFWwindow;

namespace cocos2d {
    class CCCopying {
    
    };

    class CCObject : public CCCopying {
    public:
        
    };

    class CCArray : public CCObject {
    public:
        CCObject* objectAtIndex(unsigned int index) const;
    };

    class CCPoint {
    public:
        float x;
        float y;
    };

    class CCSize {
    public:
        float width;
        float height;
    };

    class CCRect {
    public:
        float getMinX() const;
        float getMinY() const;
        float getMaxX() const;
        float getMaxY() const;

        CCPoint origin;
        CCSize size;
    };

    class CCCamera : public CCObject {
    public:
        static float getEyeXYZ(float* fEyeX, float* fEyeY, float* fEyeZ);
    };

    class CCNode : public CCObject {
    public:
        virtual int getTag() const;
        virtual unsigned int getChildrenCount(void) const;
        virtual bool isVisible();
        virtual CCArray* getChildren();
        virtual void removeFromParentAndCleanup(bool cleanup);
        virtual void* getUserData();
        virtual void setPosition(const CCPoint& position);
        virtual const CCPoint& getPosition();
        virtual float getScale();
        virtual float getScaleX();
        virtual float getScaleY();
        virtual void setScale(float scale);
        virtual void setScaleX(float fScaleX);
        virtual void setScaleY(float fScaleY);
        virtual float getRotation();
        virtual float getRotationX();
        virtual float getRotationY();
        virtual void setRotation(float fRotation);
        virtual void setRotationX(float fRotationX);
        virtual void setRotationY(float fRotationY);
        virtual const CCPoint& getAnchorPoint();
        virtual void setAnchorPoint(const CCPoint& anchorPoint);
        virtual const CCSize& getContentSize() const;
        virtual void setContentSize(const CCSize& contentSize);
        virtual int getZOrder();
        virtual void setZOrder(int zOrder);
        virtual void setVisible(bool visible);
        virtual CCNode* getParent();
        CCRect boundingBox();
        virtual CCCamera* getCamera();
        CCPoint convertToWorldSpace(CCPoint const& nodePoint);
    };

    class CCRGBAProtocol {
    public:
        virtual _ccColor3B const& getColor() = 0;
        virtual GLubyte getOpacity() = 0;
        virtual void setColor(_ccColor3B const& color) = 0;
        virtual void setOpacity(GLubyte opacity) = 0;
    };
    
    class CCNodeRGBA : public CCNode, public CCRGBAProtocol {};

    class CCLabelProtocol {
    public: 
        virtual void setString(char const* label) = 0;
        virtual char const* getString() = 0;
    };

    class CCBlendProtocol {
    
    };

    class CCTexture2D : public CCObject {};

    class CCTextureProtocol : public CCBlendProtocol {
    public:
        virtual CCTexture2D* getTexture() = 0;
        virtual void setTexture(CCTexture2D* texture) = 0;
    };

    class CCSprite : public CCNodeRGBA, public CCTextureProtocol {
    public:
        CCRect const& getTextureRect();
    };

    class CCDictElement {
    public:
        UT_hash_handle hh;
        CCObject* getObject() const;
        char const* getStrKey() const;
    };

    class CCDictionary : public CCObject {
    public:
        CCDictElement* m_pElements;
    };
  
    class CCTextureCache : public CCObject {
    public:
        static CCTextureCache* sharedTextureCache();
        CCDictionary* m_pTextures;
    };
   
    class CCSpriteFrameCache : public CCObject {
    public:
        static CCSpriteFrameCache* sharedSpriteFrameCache();
        CCDictionary* m_pSpriteFrames;
    };

    class CCSpriteFrame : public CCObject {
    public:
        CCTexture2D* getTexture();
        CCRect const& getRect();
    };

    typedef void(CCObject::*SEL_MenuHandler)(CCObject*);

    class CCMenuItem : public CCNodeRGBA {
    protected:
        SEL_MenuHandler m_pfnSelector;
    };

    class TypeInfo {

    };

    class CCScene : public CCNode {

    };

    class CCDirector : public CCObject, public TypeInfo {
    public:
        static CCDirector* sharedDirector();
        CCScene* getRunningScene();
        CCSize getWinSize();
    };

    class CCEGLViewProtocol {

    };

    class CCEGLView : public CCObject, public CCEGLViewProtocol {
    public:
        GLFWwindow* getWindow() const;
    };
}

using namespace cocos2d;

typedef char const*(__thiscall *getStrKey_t)(const CCDictElement*);
typedef CCObject*(__thiscall *objectAtIndex_t)(const CCArray*, unsigned int);
typedef CCObject*(__thiscall *getObject_t)(const CCDictElement*);
typedef CCPoint(__thiscall *convertToWorldSpace_t)(CCNode*, CCPoint const&);
typedef CCRect const&(__thiscall *getTextureRect_t)(CCSprite*);
typedef CCRect const&(__thiscall *getRect_t)(CCSpriteFrame*);
typedef CCRect(__thiscall *boundingBox_t)(CCNode*);
typedef CCScene*(__thiscall *getRunningScene_t)(CCDirector*);
typedef CCSize(__thiscall *getWinSize_t)(CCDirector*);
typedef CCTexture2D*(__thiscall *getTexture_t)(CCSpriteFrame*);
typedef float(__thiscall *getMaxX_t)(const CCRect*);
typedef float(__thiscall *getMaxY_t)(const CCRect*);
typedef float(__thiscall *getMinX_t)(const CCRect*);
typedef float(__thiscall *getMinY_t)(const CCRect*);
typedef CCDirector*(__cdecl *sharedDirector_t)();
typedef CCSpriteFrameCache*(__cdecl *sharedSpriteFrameCache_t)();
typedef CCTextureCache*(__cdecl *sharedTextureCache_t)();
typedef float(__cdecl *getEyeXYZ_t)(float*, float*, float*);
typedef GLFWwindow* (__thiscall *getWindow_t)(const CCEGLView*);

#define NO_DECLTYPE

#define CCDICT_FOREACH(__dict__, __el__)                      \
    CCDictElement* pTmp##__dict__##__el__ = NULL;             \
    if (__dict__)                                             \
        HASH_ITER(hh, (__dict__)->m_pElements, __el__, pTmp##__dict__##__el__)

#ifdef NO_DECLTYPE
#define HASH_ITER(hh, head, el, tmp)                                                      \
    for ((el) = (head), (*(char**)(&(tmp))) = (char*)((head) ? (head)->hh.next : NULL);   \
         el;                                                                              \
         (el) = (tmp), (*(char**)(&(tmp))) = (char*)((tmp) ? (tmp)->hh.next : NULL)) 
#else
#define HASH_ITER(hh, head, el, tmp)                                                      \
    for ((el) = (head), (tmp) = DECLTYPE(el)((head) ? (head)->hh.next : NULL);            \
         el;                                                                              \
         (el) = (tmp), (tmp) = DECLTYPE(el)((tmp) ? (tmp)->hh.next : NULL))
#endif
