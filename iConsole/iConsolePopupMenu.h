//
//  QBPopupMenu.h
//  QBPopupMenu
//
//  Created by Tanaka Katsuma on 2013/11/22.
//  Copyright (c) 2013年 Katsuma Tanaka. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "iConsolePopupMenuItem.h"


#undef weak_safe
#if __has_feature(objc_arc_weak)
#define weak_safe weak
#else
#define weak_safe unsafe_unretained
#endif

@class iConsolePopupMenu;
@class iConsolePopupMenuItemView;
@class iConsolePopupMenuPagenatorView;

@protocol QBPopupMenuDelegate <NSObject>

@optional
- (void)popupMenuWillAppear:(iConsolePopupMenu *)popupMenu;
- (void)popupMenuDidAppear:(iConsolePopupMenu *)popupMenu;
- (void)popupMenuWillDisappear:(iConsolePopupMenu *)popupMenu;
- (void)popupMenuDidDisappear:(iConsolePopupMenu *)popupMenu;

@end

typedef NS_ENUM(NSUInteger, QBPopupMenuArrowDirection) {
    QBPopupMenuArrowDirectionDefault,
    QBPopupMenuArrowDirectionUp,
    QBPopupMenuArrowDirectionDown,
    QBPopupMenuArrowDirectionLeft,
    QBPopupMenuArrowDirectionRight
};

@interface iConsolePopupMenu : UIView

@property (nonatomic, weak_safe) id<QBPopupMenuDelegate> delegate;

@property (nonatomic, assign, getter = isVisible, readonly) BOOL visible;
@property (nonatomic, copy) NSArray *items;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGFloat cornerRadius;
@property (nonatomic, assign) CGFloat arrowSize;
@property (nonatomic, assign) QBPopupMenuArrowDirection arrowDirection;
@property (nonatomic, assign) UIEdgeInsets popupMenuInsets;
@property (nonatomic, assign) CGFloat margin;

@property (nonatomic, strong) UIColor *color;
@property (nonatomic, strong) UIColor *highlightedColor;

+ (instancetype)popupMenuWithItems:(NSArray *)items;
- (instancetype)initWithItems:(NSArray *)items;

- (void)showInView:(UIView *)view targetRect:(CGRect)targetRect animated:(BOOL)animated;
- (void)dismissAnimated:(BOOL)animated;
- (void)updateWithTargetRect:(CGRect)targetRect;

// NOTE: When subclassing this class, use these methods to customize the appearance.
+ (Class)itemViewClass;
+ (Class)pagenatorViewClass;

- (CGMutablePathRef)arrowPathInRect:(CGRect)rect direction:(QBPopupMenuArrowDirection)direction CF_RETURNS_RETAINED;
- (CGMutablePathRef)headPathInRect:(CGRect)rect cornerRadius:(CGFloat)cornerRadius CF_RETURNS_RETAINED;
- (CGMutablePathRef)tailPathInRect:(CGRect)rect cornerRadius:(CGFloat)cornerRadius CF_RETURNS_RETAINED;
- (CGMutablePathRef)bodyPathInRect:(CGRect)rect CF_RETURNS_RETAINED;

- (void)drawArrowAtPoint:(CGPoint)point arrowSize:(CGFloat)arrowSize arrowDirection:(QBPopupMenuArrowDirection)arrowDirection highlighted:(BOOL)highlighted;
- (void)drawArrowInRect:(CGRect)rect direction:(QBPopupMenuArrowDirection)direction highlighted:(BOOL)highlighted;
- (void)drawHeadInRect:(CGRect)rect cornerRadius:(CGFloat)cornerRadius highlighted:(BOOL)highlighted;
- (void)drawTailInRect:(CGRect)rect cornerRadius:(CGFloat)cornerRadius highlighted:(BOOL)highlighted;
- (void)drawBodyInRect:(CGRect)rect firstItem:(BOOL)firstItem lastItem:(BOOL)lastItem highlighted:(BOOL)highlighted;

@end