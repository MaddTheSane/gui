/* 
   GSNibCompatibility.h

   Copyright (C) 1997, 1999 Free Software Foundation, Inc.

   Author:  Gregory John Casamento <greg_casamento@yahoo.com>
   Date: 2002
   
   This file is part of the GNUstep GUI Library.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; see the file COPYING.LIB.
   If not, see <http://www.gnu.org/licenses/> or write to the 
   Free Software Foundation, 51 Franklin Street, Fifth Floor, 
   Boston, MA 02110-1301, USA.
*/ 

#ifndef _GNUstep_H_GSNibCompatibility
#define _GNUstep_H_GSNibCompatibility

#import <Foundation/NSObject.h>

#import <AppKit/NSButton.h>
#import <AppKit/NSControl.h>
#import <AppKit/NSEvent.h>
#import <AppKit/NSGraphicsContext.h>
#import <AppKit/NSGraphics.h>
#import <AppKit/NSMenu.h>
#import <AppKit/NSNibConnector.h>
#import <AppKit/NSResponder.h>
#import <AppKit/NSText.h>
#import <AppKit/NSTextView.h>
#import <AppKit/NSView.h>
#import <AppKit/NSWindow.h>
#import <AppKit/NSInterfaceStyle.h>
#import <AppKit/NSNibConnector.h>

#import "GNUstepGUI/GSNibContainer.h"
#import "GNUstepGUI/GSInstantiator.h"

@class NSDictionary;
@class NSMapTable;
@class NSMutableArray;
@class NSMutableSet;
@class NSString;

// templates
@protocol OSXNibTemplate
- (void) setClassName: (NSString *)className;
- (NSString *)className;
- (void) setRealObject: (id)o;
- (id) realObject;
@end

@protocol GSNibLoading
- (id) nibInstantiate;
@end

#ifdef NeXT_RUNTIME
// Apple run-time

#import <AppKit/NSUserInterfaceItemIdentification.h>

// These classes aren't defined publicly by Apple, so they were taken
// from 10.12.4's AppKit framework using class-dump

@interface NSIBHelpConnector : NSObject <NSCoding>
{
  id _destination;
  NSString *_file;
  NSString *_marker;
}

- (void)instantiateWithObjectInstantiator:(id)arg1;
- (void)establishConnection;
- (void)replaceObject:(id)arg1 withObject:(id)arg2;
- (void)setMarker:(NSString *)arg1;
- (NSString *)marker;
- (void)setFile:(NSString *)arg1;
- (NSString *)file;
- (void)setLabel:(id)arg1;
- (id)label;
- (void)setDestination:(id)arg1;
- (id)destination;
- (void)setSource:(id)arg1;
- (id)source;
- (id)init;

@end

struct NSButtonState {
  long long _field1;
  char _field2;
  char _field3;
  char _field4;
};

@interface NSButtonImageSource : NSObject <NSCoding, NSCopying>
{
  NSMutableDictionary *_buttonImages;
  struct CGSize _imageSize;
  struct CGSize _focusRingImageSize;
  struct {
    unsigned int hasAlpha:1;
    unsigned int fullEncoding:1;
    unsigned int reserved:30;
  } _bisFlags;
  int _reserved1;
  int _reserved2;
  int _reserved3;
}

+ (BOOL)archiveButtonImageSourceWithName:(id)arg1 toDirectory:(id)arg2;
+ (id)buttonImageSourceWithName:(id)arg1;
- (BOOL)hasImageWithAlpha;
- (NSSize)focusRingImageSize;
- (NSSize)imageSize;
- (BOOL)useHighlightEffectForState:(struct NSButtonState)arg1;
- (BOOL)useDisabledEffectForState:(struct NSButtonState)arg1;
- (BOOL)isOpaqueForState:(struct NSButtonState)arg1;
- (BOOL)isBorderedForState:(struct NSButtonState)arg1;
- (unsigned long long)bezelStyleForState:(struct NSButtonState)arg1;
- (id)focusRingImageForState:(struct NSButtonState)arg1;
- (id)imageForState:(struct NSButtonState)arg1;
- (id)_findButtonImageForState:(struct NSButtonState)arg1;
- (BOOL)_archiveToFile:(id)arg1;
- (id)_initWithWidget:(CFStringRef)arg1;
- (id)_initWithName:(id)arg1 propertyList:(id)arg2;
- (void)_scanImages;

@end

@interface NSWindowTemplate : NSObject <NSCoding, NSUserInterfaceItemIdentification>
{
  NSRect windowRect;
  int windowStyleMask;
  int windowBacking;
  NSString *windowTitle;
  id viewClass;
  NSString *windowClass;
  id windowView;
  NSWindow *realObject;
  id extension;
  NSSize minSize;
  struct __WtFlags {
    unsigned int _PADDING:9;
    unsigned int isRestorable:1;
    unsigned int hidesToolbarButton:1;
    unsigned int autorecalculatesKeyViewLoop:1;
    unsigned int hideShadow:1;
    unsigned int allowsToolTipsWhenInactive:1;
    unsigned int autoSetMiniaturizableMask:1;
    unsigned int autoSetZoomableMask:1;
    unsigned int :2;
    unsigned int savePosition:1;
    unsigned int autoPositionMask:6;
    unsigned int dynamicDepthLimit:1;
    unsigned int wantsToBeColor:1;
    unsigned int visible:1;
    unsigned int oneShot:1;
    unsigned int defer:1;
    unsigned int dontFreeWhenClosed:1;
    unsigned int hidesOnDeactivate:1;
  } _wtFlags;
  NSRect screenRect;
  NSString *frameAutosaveName;
  NSSize maxSize;
  NSSize contentMinSize;
  NSSize contentMaxSize;
  unsigned long long windowBackingLocation;
  unsigned long long windowSharingType;
  char autorecalculateContentBorderThicknesses[4];
  double contentBorderThicknesses[4];
  NSString *userInterfaceIdentifier;
  unsigned long long animationBehavior;
  unsigned long long collectionBehavior;
  BOOL isRestorableWasDecodedFromArchive;
  NSAppearance *appearance;
  NSViewController *_contentViewController;
  NSSize _minFullScreenContentSize;
  NSSize _maxFullScreenContentSize;
  BOOL _minFullScreenContentSizeIsSet;
  BOOL _maxFullScreenContentSizeIsSet;
  NSString *_tabbingIdentifier;
  long long _tabbingMode;
}

+ (void)initialize;
@property BOOL maxFullScreenContentSizeIsSet; // @synthesize maxFullScreenContentSizeIsSet=_maxFullScreenContentSizeIsSet;
@property BOOL minFullScreenContentSizeIsSet; // @synthesize minFullScreenContentSizeIsSet=_minFullScreenContentSizeIsSet;
@property long long tabbingMode; // @synthesize tabbingMode=_tabbingMode;
@property(copy, nonatomic) NSString *tabbingIdentifier; // @synthesize tabbingIdentifier=_tabbingIdentifier;
@property(retain, nonatomic) NSViewController *contentViewController; // @synthesize contentViewController=_contentViewController;
@property(retain, nonatomic) NSAppearance *appearance; // @synthesize appearance;
@property(copy) NSString *identifier;
- (void)setUserInterfaceItemIdentifier:(id)arg1;
- (id)userInterfaceItemIdentifier;
- (id)initWithCoder:(id)arg1;
- (id)init;
@property NSSize maxFullScreenContentSize;
@property NSSize minFullScreenContentSize;
- (void)encodeWithCoder:(id)arg1;
- (id)nibInstantiate;
- (BOOL)isRestorable;
- (void)setRestorable:(BOOL)arg1;
- (unsigned long long)collectionBehavior;
- (void)setCollectionBehavior:(unsigned long long)arg1;
- (long long)animationBehavior;
- (void)setAnimationBehavior:(long long)arg1;
- (double)contentBorderThicknessForEdge:(unsigned long long)arg1;
- (void)setContentBorderThickness:(double)arg1 forEdge:(unsigned long long)arg2;
- (BOOL)autorecalculatesContentBorderThicknessForEdge:(unsigned long long)arg1;
- (void)setAutorecalculatesContentBorderThickness:(BOOL)arg1 forEdge:(unsigned long long)arg2;
- (void)setShowsToolbarButton:(BOOL)arg1;
- (BOOL)showsToolbarButton;
- (void)setContentMinSize:(struct CGSize)arg1;
- (struct CGSize)contentMinSize;
- (void)setContentMaxSize:(struct CGSize)arg1;
- (struct CGSize)contentMaxSize;
- (void)setWindowBackingLocation:(unsigned long long)arg1;
- (unsigned long long)windowBackingLocation;
- (void)setWindowSharingType:(unsigned long long)arg1;
- (unsigned long long)windowSharingType;
- (void)setToolbar:(id)arg1;
- (id)toolbar;
- (BOOL)autorecalculatesKeyViewLoop;
- (void)setAutorecalculatesKeyViewLoop:(BOOL)arg1;
- (BOOL)hasShadow;
- (void)setHasShadow:(BOOL)arg1;
- (BOOL)allowsToolTipsWhenApplicationIsInactive;
- (void)setAllowsToolTipsWhenApplicationIsInactive:(BOOL)arg1;
- (void)setMaxSize:(struct CGSize)arg1;
- (struct CGSize)maxSize;
- (void)setMinSize:(struct CGSize)arg1;
- (struct CGSize)minSize;
- (id)frameAutosaveName;
- (void)setFrameAutosaveName:(id)arg1;
- (void)setInterfaceStyle:(unsigned long long)arg1;
- (unsigned long long)interfaceStyle;
- (void)setAutoPositionMask:(unsigned long long)arg1;
- (unsigned long long)autoPositionMask;
- (void)setWantsToBeColor:(BOOL)arg1;
- (BOOL)wantsToBeColor;
- (void)setHidesOnDeactivate:(BOOL)arg1;
- (BOOL)hidesOnDeactivate;
- (void)setReleasedWhenClosed:(BOOL)arg1;
- (BOOL)isReleasedWhenClosed;
- (void)setDeferred:(BOOL)arg1;
- (BOOL)isDeferred;
- (void)setDynamicDepthLimit:(BOOL)arg1;
- (BOOL)hasDynamicDepthLimit;
- (void)setOneShot:(BOOL)arg1;
- (BOOL)isOneShot;
- (void)setBackingType:(unsigned long long)arg1;
- (unsigned long long)backingType;
- (void)setStyleMask:(unsigned long long)arg1;
- (unsigned long long)styleMask;
- (Class)windowClassForNibInstantiate;
- (void)setClassName:(id)arg1;
- (id)className;
- (void)setTitle:(id)arg1;
- (id)title;

@end

@interface NSViewTemplate : NSView
{
  NSString *_className;
}

- (id)awakeAfterUsingCoder:(id)arg1;
- (id)createRealObject;
- (void)setClassName:(NSString *)arg1;
- (NSString *)className;
- (id)initWithFrame:(NSRect)arg1;
- (id)initWithView:(id)arg1 className:(NSString *)arg2;

@end

@interface NSTextTemplate : NSViewTemplate
{
  id _contents;
  NSColor *_textColor;
  NSFont *_font;
  unsigned long long _alignment;
  NSColor *_backgroundColor;
  struct CGSize _minSize;
  struct CGSize _maxSize;
  id _delegate;
  struct __ttFlags {
    unsigned int drawsBackground:1;
    unsigned int selectable:1;
    unsigned int editable:1;
    unsigned int richText:1;
    unsigned int importsGraphics:1;
    unsigned int horizontallyResizable:1;
    unsigned int verticallyResizable:1;
    unsigned int fieldEditor:1;
    unsigned int usesFontPanel:1;
    unsigned int rulerVisible:1;
    unsigned int allowsUndo:1;
    unsigned int _pad:21;
  } _ttFlags;
}

- (id)createRealObject;
- (id)initWithView:(id)arg1 className:(NSString *)arg2;

@end

@interface NSTextViewTemplate : NSViewTemplate
{
  id _contents;
  NSColor *_backgroundColor;
  NSDictionary *_selectedTextAttributes;
  NSColor *_insertionPointColor;
  NSSize _containerSize;
  NSSize _minSize;
  NSSize _maxSize;
  id _delegate;
  struct __tvtFlags {
    unsigned int drawsBackground:1;
    unsigned int selectable:1;
    unsigned int editable:1;
    unsigned int richText:1;
    unsigned int importsGraphics:1;
    unsigned int horizontallyResizable:1;
    unsigned int verticallyResizable:1;
    unsigned int fieldEditor:1;
    unsigned int usesFontPanel:1;
    unsigned int rulerVisible:1;
    unsigned int containerTracksWidth:1;
    unsigned int containerTracksHeight:1;
    unsigned int usesRuler:1;
    unsigned int allowsUndo:1;
    unsigned int _pad:18;
  } _tvtFlags;
  NSDictionary *_typingAttrs;
}

- (id)createRealObject;
- (id)initWithView:(id)arg1 className:(NSString *)arg2;

@end

@interface NSMenuTemplate : NSObject <NSCoding>
{
  NSString *title;
  NSPoint location;
  id view;
  NSString *menuClassName;
  id supermenu;
  id realObject;
  id extension;
  BOOL isWindowsMenu;
  BOOL isRequestMenu;
  BOOL isFontMenu;
  BOOL interfaceStyle;
  char *cMenuClassName;
  BOOL disabled;
  id popupCell;
}

- (long long)numberOfItems;
- (void)_setOwnedByPopUp:(id)arg1;
- (BOOL)_isEnabled;
- (void)_setEnabled:(BOOL)arg1;
- (id)nibInstantiate;
- (BOOL)_pullsDown;
- (void)_setPullsDown:(BOOL)arg1;
- (void)setSupermenu:(id)arg1;
- (void)_setTitle:(NSString *)arg1;
- (id)itemMatrix;
- (id)supermenu;
- (NSString *)menuClassName;
- (void)_setMenuClassName:(NSString *)arg1;

@end


@interface NSCustomObject : NSObject <NSCoding>
{
  NSString *className;
  id object;
  id extension;
}

- (void)setClassName:(NSString *)arg1;
- (NSString *)className;
- (void)setObject:(id)arg1;
- (id)nibInstantiate;
- (id)init;

@end

@interface NSCustomView : NSView
{
  NSString *className;
  NSView *view;
  id extension;
}

- (void)setClassName:(NSString *)arg1;
- (NSString *)className;
- (id)nibInstantiateWithObjectInstantiator:(id)arg1;
- (BOOL)_descendantIsConstrainedByConstraint:(id)arg1;
- (void)_setAsClipViewDocumentViewIfNeeded;
- (id)initWithFrame:(NSRect)arg1;

@end

@interface NSCustomResource : NSObject <NSCoding>
{
  NSString *className;
  NSString *resourceName;
}

+ (id)bundleForImageSearch;
+ (id)bundleForCurrentNib;
+ (void)popBundleForImageSearch;
+ (void)pushBundleForImageSearch:(id)arg1;
- (id)awakeAfterUsingCoder:(id)arg1;
- (id)loadSoundWithName:(id)arg1;
- (id)loadCIImageWithName:(id)arg1;
- (id)loadImageWithName:(id)arg1;
- (id)_loadImageWithName:(id)arg1;
- (void)setResourceName:(NSString *)arg1;
- (NSString *)resourceName;
- (void)setClassName:(NSString *)arg1;
- (NSString *)className;

@end


@interface NSClassSwapper : NSObject <NSCoding>
{
  NSString *className;
  id template;
}

- (void)setClassName:(NSString *)arg1;
- (NSString *)className;
- (void)setTemplate:(id)arg1;
- (id)template;
- (id)init;

@end

@class NSIBObjectDataAuxilary;

@interface NSIBObjectData : NSObject <NSCoding>
{
  id rootObject;
  NSMapTable *objectTable;
  NSMapTable *nameTable;
  NSMutableSet *visibleWindows;
  NSMutableArray *connections;
  id firstResponder;
  id fontManager;
  NSMapTable *oidTable;
  unsigned long long nextOid;
  NSMapTable *classTable;
  NSMapTable *instantiatedObjectTable;
  NSString *targetFramework;
  id _document;
  NSIBObjectDataAuxilary *_objectDataAuxilary;
}

- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (void)_removeEarlyDecodingObjectConnectionsFromConnections:(id)arg1;
- (void)_addEarlyDecodingObjectsFromObjectList:(id)arg1 toConnections:(id)arg2;
- (void)nibInstantiateWithOwner:(id)arg1 options:(id)arg2 topLevelObjects:(id)arg3;
- (void)nibInstantiateWithOwner:(id)arg1 topLevelObjects:(id)arg2;
- (void)nibInstantiateWithOwner:(id)arg1;
- (id)instantiateObject:(id)arg1;
- (void)setShouldEncodeDesigntimeData:(BOOL)arg1;
- (BOOL)shouldEncodeDesigntimeData;
- (NSMapTable *)classTable;
- (NSMapTable *)oidTable;
- (NSMapTable *)nameTable;
- (NSMapTable *)objectTable;
- (void)setRootObject:(id)arg1;
- (id)rootObject;
- (void)setFirstResponder:(id)arg1;
- (id)firstResponder;
- (void)setNextObjectID:(unsigned long long)arg1;
- (long long)nextObjectID;
- (void)setTargetFramework:(NSString *)arg1;
- (NSString *)targetFramework;
- (void)setConnections:(NSArray*)arg1;
- (NSArray*)connections;
- (void)setVisibleWindows:(NSMutableSet *)arg1;
- (NSMutableSet *)visibleWindows;
- (id)init;
- (void)_assignObjectIds;
- (void)_readVersion0:(id)arg1;
- (void)_encodeMapTable:(id)arg1 forTypes:(const char *)arg2 withCoder:(id)arg3;
- (void)_encodeIntValuedMapTable:(id)arg1 withCoder:(id)arg2;
- (void)_encodeObjectValuedMapTable:(id)arg1 withCoder:(id)arg2;

@end

@interface NSPSMatrix : NSObject <NSCoding>
{
  CGFloat matrixElements[12];
  struct _mFlags {
    unsigned int identity:1;
    unsigned int rotated:1;
    unsigned int rotationOnly:1;
    unsigned int _RESERVED:13;
  } mFlags;
}

- (struct CGAffineTransform)CGAffineTransform;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)_computeInv;
- (id)invTransformRect:(CGRect *)arg1;
- (id)transformRect:(CGRect *)arg1;
- (BOOL)rotated;
- (BOOL)identity;
- (id)makeIdentity;
- (id)invTransform:(CGPoint *)arg1;
- (id)transform:(CGPoint *)arg1;
- (id)sendInv;
- (id)send;
- (id)concat:(id)arg1;
- (void)setFrameRotation:(CGFloat)arg1;
- (id)translateTo:(CGFloat)arg1:(CGFloat)arg2;
- (id)scaleTo:(CGFloat)arg1:(CGFloat)arg2;
- (void)rotateByAngle:(CGFloat)arg1;
- (void)translateOriginToPoint:(CGPoint)arg1;
- (void)scaleUnitSquareToSize:(CGSize)arg1;
- (double)getRotationAngle;
- (id)_doRotationOnly;
- (id)init;

@end

@interface NSNibAXAttributeConnector : NSObject <NSCoding>
{
  id _destination;
  NSString *_attributeType;
  NSString *_attributeValue;
}

- (void)setLabel:(id)arg1;
- (id)label;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (void)instantiateWithObjectInstantiator:(id)arg1;
- (void)establishConnection;
- (void)replaceObject:(id)arg1 withObject:(id)arg2;
- (void)setDestination:(id)arg1;
- (id)destination;
- (void)setSource:(id)arg1;
- (id)source;
- (void)setAttributeValue:(id)arg1;
- (id)attributeValue;
- (void)setAttributeType:(id)arg1;
- (id)attributeType;
- (void)dealloc;
- (BOOL)_isAXConnector;

@end

@interface NSNibAXRelationshipConnector : NSNibConnector

- (void)establishConnection;
- (BOOL)_isAXConnector;

@end

@interface NSNibBindingConnector : NSNibConnector <NSCoding>
{
  NSString *_binding;
  NSString *_keyPath;
  NSDictionary *_options;
  struct __nibBindingConnectorFlags {
    unsigned int _hasEstablishedConnection:1;
    unsigned int _reservedNibBindingConnector:31;
  } _nibBindingConnectorFlags;
  NSNibBindingConnector *_previousConnector;
}

- (NSString*)description;
- (void)instantiateWithObjectInstantiator:(id)arg1;
- (void)establishConnection;
- (void)replaceObject:(id)arg1 withObject:(id)arg2;
- (NSNibBindingConnector *)_previousNibBindingConnector;
- (void)_setPreviousNibBindingConnector:(NSNibBindingConnector *)arg1;
- (NSDictionary *)options;
- (void)setOptions:(NSDictionary *)arg1;
- (NSString *)keyPath;
- (void)setKeyPath:(NSString *)arg1;
- (NSString *)binding;
- (void)setBinding:(NSString *)arg1;
- (void)_updateLabel;
- (void)_updateForVersion:(long long)arg1;
- (id)init;

@end

@interface NSIBUserDefinedRuntimeAttributesConnector : NSObject
{
  NSArray *keyPaths;
  NSArray *values;
  id object;
}

- (void)instantiateWithObjectInstantiator:(id)arg1;
- (void)establishConnection;
- (void)replaceObject:(id)arg1 withObject:(id)arg2;
- (void)setLabel:(id)arg1;
- (id)label;
- (void)setDestination:(id)arg1;
- (id)destination;
- (void)setSource:(id)arg1;
- (id)source;
- (void)setObject:(id)arg1;
- (id)object;
- (void)setValues:(NSArray *)arg1;
- (NSArray *)values;
- (void)setKeyPaths:(NSArray *)arg1;
- (NSArray *)keyPaths;

@end

#else
// GNUstep run-time
typedef struct _GSWindowTemplateFlags
{
#if GS_WORDS_BIGENDIAN == 1
  unsigned int isHiddenOnDeactivate:1;
  unsigned int isNotReleasedOnClose:1;
  unsigned int isDeferred:1;
  unsigned int isOneShot:1;
  unsigned int isVisible:1;
  unsigned int wantsToBeColor:1;
  unsigned int dynamicDepthLimit:1;
  unsigned int autoPositionMask:6;
  unsigned int savePosition:1;
  unsigned int style:2;
  unsigned int _unused2:3;
  unsigned int isNotShadowed:1;
  unsigned int autorecalculatesKeyViewLoop:1;
  unsigned int _unused:11; // currently not used, contains Cocoa specific info
#else
  unsigned int _unused:11; // currently not used, contains Cocoa specific info
  unsigned int autorecalculatesKeyViewLoop:1;
  unsigned int isNotShadowed:1;
  unsigned int _unused2:3;
  unsigned int style:2;
  unsigned int savePosition:1;
  unsigned int autoPositionMask:6;
  unsigned int dynamicDepthLimit:1;
  unsigned int wantsToBeColor:1;
  unsigned int isVisible:1;
  unsigned int isOneShot:1;
  unsigned int isDeferred:1;
  unsigned int isNotReleasedOnClose:1;
  unsigned int isHiddenOnDeactivate:1;
#endif
} GSWindowTemplateFlags;

// help connector class...
APPKIT_EXPORT_CLASS
@interface NSIBHelpConnector : NSNibConnector
{
  id _marker;
  id _file;
}
- (void) setFile: (id)file;
- (id) file;
- (void) setMarker: (id)file;
- (id) marker;
@end
/**
 * Button image source class.
 */
APPKIT_EXPORT_CLASS
@interface NSButtonImageSource : NSObject <NSCoding>
{
  NSString *imageName;
}
- (id) initWithImageNamed: (NSString *)name;
- (NSString *)imageName;
@end

/**
 * This class acts as a placeholder for the window.  It doesn't derive from
 * NSWindow for two reasons. First, it shouldn't instantiate a window immediately
 * when it's unarchived and second, it holds certain attributes (but doesn't set them
 * on the window, when the window is being edited in the application builder.
 */
APPKIT_EXPORT_CLASS
@interface NSWindowTemplate : NSObject <OSXNibTemplate, NSCoding, GSNibLoading>
{
  @public
  NSBackingStoreType   _backingStoreType;
  NSSize               _maxSize;
  NSSize               _minSize;
  unsigned             _windowStyle;
  NSString            *_title;
  NSString            *_viewClass;
  NSString            *_windowClass;
  NSRect               _windowRect;
  NSRect               _screenRect;
  id                   _realObject;
  id                   _view;
  GSWindowTemplateFlags _flags;
  NSString            *_autosaveName;
  Class               _baseWindowClass;
  NSToolbar           *_toolbar;
}
- (id) initWithWindow: (NSWindow *)window
	    className: (NSString *)windowClass
           isDeferred: (BOOL) deferred
	    isOneShot: (BOOL) oneShot
	    isVisible: (BOOL) visible
       wantsToBeColor: (BOOL) wantsToBeColor
     autoPositionMask: (int) autoPositionMask;
- (void) setBackingStoreType: (NSBackingStoreType)type;
- (NSBackingStoreType) backingStoreType;
- (void) setDeferred: (BOOL)flag;
- (BOOL) isDeferred;
- (void) setMaxSize: (NSSize)maxSize;
- (NSSize) maxSize;
- (void) setMinSize: (NSSize)minSize;
- (NSSize) minSize;
- (void) setWindowStyle: (unsigned)sty;
- (unsigned) windowStyle;
- (void) setTitle: (NSString *) title;
- (NSString *)title;
- (void) setViewClass: (NSString *)viewClass;
- (NSString *)viewClass;
- (void) setWindowRect: (NSRect)rect;
- (NSRect)windowRect;
- (void) setScreenRect: (NSRect)rect;
- (NSRect) screenRect;
- (void) setView: (id)view;
- (id) view;
- (Class) baseWindowClass;
@end

APPKIT_EXPORT_CLASS
@interface NSViewTemplate : NSView <OSXNibTemplate, NSCoding>
{
  NSString            *_className;
  id                   _realObject;
}
- (id) initWithObject: (id)o
            className: (NSString *)name;
@end

APPKIT_EXPORT_CLASS
@interface NSTextTemplate : NSViewTemplate
{
}
@end

APPKIT_EXPORT_CLASS
@interface NSTextViewTemplate : NSViewTemplate
{
}
@end

APPKIT_EXPORT_CLASS
@interface NSMenuTemplate : NSObject <OSXNibTemplate, NSCoding>
{
  NSString            *_menuClass;
  NSString            *_title;
  id                   _realObject;
  id                   _parentMenu;
  NSPoint              _location;
  BOOL                 _isWindowsMenu;
  BOOL                 _isServicesMenu;
  BOOL                 _isFontMenu;
  NSInterfaceStyle     _interfaceStyle;
}
- (void) setClassName: (NSString *)name;
- (NSString *)className;
@end

APPKIT_EXPORT_CLASS
@interface NSCustomObject : NSObject <NSCoding, GSNibLoading>
{
  NSString *_className;
  NSString *_extension;
  id _object;
}
- (void) setClassName: (NSString *)name;
- (NSString *)className;
- (void) setExtension: (NSString *)ext;
- (NSString *)extension;
- (void) setRealObject: (id)obj;
- (id) realObject;
@end

APPKIT_EXPORT_CLASS
@interface NSCustomView : NSView <GSNibLoading>
{
  NSString *_className;
  NSString *_extension;
  NSView *_superview;
  NSView *_view;
}
- (void) setClassName: (NSString *)name;
- (NSString *)className;
- (void) setExtension: (NSString *)view;
- (NSString *)extension;
- (id)nibInstantiateWithCoder: (NSCoder *)coder;
@end

APPKIT_EXPORT_CLASS
@interface NSCustomResource : NSObject <NSCoding>
{
  NSString *_className;
  NSString *_resourceName;
}
- (void) setClassName: (NSString *)className;
- (NSString *)className;
- (void) setResourceName: (NSString *)view;
- (NSString *)resourceName;
@end

APPKIT_EXPORT_CLASS
@interface NSClassSwapper : NSObject <NSCoding>
{
  NSString *_className;
  NSString *_originalClassName;
  id _template;
}
- (id) initWithObject: (id)object 
        withClassName: (NSString *)className
    originalClassName: (NSString *)origClassName;
+ (void) setIsInInterfaceBuilder: (BOOL)flag;
+ (BOOL) isInInterfaceBuilder;
- (void) setTemplate: (id)temp;
- (id) template;
- (void) setClassName: (NSString *)className;
- (NSString *)className;
- (void) setOriginalClassName: (NSString *)className;
- (NSString *)originalClassName;
@end

APPKIT_EXPORT_CLASS
@interface NSIBObjectData : NSObject <NSCoding, GSInstantiator, GSNibContainer>
{
  id              _root;
  NSMapTable     *_objects;
  NSMapTable     *_names;
  NSMapTable     *_oids;
  NSMapTable     *_classes;
  NSMapTable     *_instantiatedObjs;
  NSMutableArray *_visibleWindows;
  NSMutableArray *_connections;
  id              _firstResponder;
  id              _fontManager;
  NSString       *_framework;
  unsigned        _nextOid;
  NSMutableArray *_accessibilityConnectors;
  NSMapTable     *_accessibilityOids;
  NSMutableSet   *_topLevelObjects;
}
- (id) instantiateObject: (id)obj;
- (void) nibInstantiateWithOwner: (id)owner topLevelObjects: (NSMutableArray *)toplevel;
- (id) objectForName: (NSString *)name;
- (NSString *) nameForObject: (id)name;
- (NSMapTable *) objects;
- (NSMapTable *) names;
- (NSMapTable *) classes;
- (NSMapTable *) oids;
- (NSMutableArray *) visibleWindows;
- (void) setRoot: (id)root;
- (id) root;
- (void) setNextOid: (int)noid;
- (int) nextOid;
@end

// class needed for nib encoding/decoding by the progress bar...
APPKIT_EXPORT_CLASS
@interface NSPSMatrix : NSObject
@end

APPKIT_EXPORT_CLASS
@interface NSNibAXAttributeConnector : NSObject <NSCoding>
{
  NSString *_attributeType;
  NSString *_attributeValue;
  id _destination;
  id _source;
  NSString *_label;
}

// Attribute name/type.
- (NSString *) attributeType;
- (void) setAttributeType: (NSString *)type;
- (NSString *) attributeValue;
- (void) setAttributeValue: (NSString *)value;

// Source destination, connectors.
- (id) destination;
- (void) setDestination: (id)destination;
- (NSString *) label;
- (void) setLabel: (NSString *)label;
- (id) source;
- (void) setSource: (id)source;

// establish connection...
- (void) establishConnection;
@end

APPKIT_EXPORT_CLASS
@interface NSNibAXRelationshipConnector : NSNibConnector
@end

@interface NSNibBindingConnector: NSNibConnector
{
  NSDictionary *_options;
  NSString *_binding;
  NSString *_keyPath;
  BOOL _hasEstablishedConnection;
}

- (NSString *) binding;
- (NSString *) keyPath;
- (NSDictionary *) options;
- (void) setBinding: (NSString *)bindings;
- (void) setKeyPath: (NSString *)keyPath;
- (void) setOptions: (NSDictionary *)options;
@end

APPKIT_EXPORT_CLASS
@interface NSIBUserDefinedRuntimeAttributesConnector : NSObject <NSCoding>
{
  id _object;
  NSArray *_keyPaths;
  NSArray *_values;
}

- (void) instantiateWithObjectInstantiator: (id)instantiator;
- (void) establishConnection;
/*
- (void) replaceObject: (id)anObject withObject: (id)anotherObject;
- (void) setLabel: (id)label;
- (id) label;
- (void) setDestination: (id)destination;
- (id) destination;
- (void) setSource: (id)source;
- (id) source;
*/
- (void) setObject: (id)object;
- (id) object;
- (void) setValues: (id)values;
- (id) values;
- (void) setKeyPaths: (id)keyPaths;
- (id) keyPaths;
@end

#endif

#endif /* _GNUstep_H_GSNibCompatibility */
