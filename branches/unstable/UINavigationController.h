/*
 *     Generated by class-dump 3.1.1.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2006 by Steve Nygard.
 */

#import "UIViewController.h"

@class NSMutableArray, UINavigationBar, UITransitionView, UIView;

@interface UINavigationController : UIViewController
{
    id _delegate;
    UITransitionView *_overlayTransitionView;
    UINavigationBar *_navigationBar;
    UIView *_accessoryView;
    UITransitionView *_transitionView;
    NSMutableArray *_viewControllers;
    UIViewController *_overlayViewController;
    unsigned int _isPoppingViewController:1;
    unsigned int _isTransitioningOverlay:1;
    unsigned int _isPoppingNavigationItem:1;
    unsigned int _isAnimating:1;
    unsigned int _isEditing:1;
    unsigned int _isDisplayed:1;
    unsigned int _dummy:26;
}

+ (void)setCustomTransitionDuration:(double)fp8;
- (id)init;
- (id)initWithNavigationBar:(id)fp8;
- (id)initWithRootViewController:(id)fp8;
- (void)dealloc;
- (void)setDelegate:(id)fp8;
- (struct CGRect)_childViewFrame;
- (id)topViewController;
- (id)visibleViewController;
- (id)navigationBar;
- (void)_setAccessoryView:(id)fp8 animate:(BOOL)fp12 goingBack:(BOOL)fp16;
- (id)_previousViewController;
- (id)view;
- (void)viewWillDisplayWithAnimation:(BOOL)fp8;
- (void)viewDidDisplayWithAnimation:(BOOL)fp8;
- (void)viewWillHideWithAnimation:(BOOL)fp8;
- (void)viewDidHideWithAnimation:(BOOL)fp8;
- (void)viewWasAddedToSuperview;
- (void)_didFinishPushingOverlayViewController;
- (void)_didFinishPoppingOverlayViewController;
- (void)_didFinishPushingViewController;
- (void)_didFinishPoppingViewController;
- (void)transitionViewDidComplete:(id)fp8;
- (double)durationForTransition:(int)fp8;
- (void)pushViewControllerWithView:(id)fp8 navigationTitle:(id)fp12;
- (void)pushViewController:(id)fp8;
- (void)pushViewController:(id)fp8 transition:(int)fp12;
- (void)popViewController;
- (void)popViewControllerWithTransition:(int)fp8;
- (void)popToRootViewController;
- (void)popToRootViewControllerWithTransition:(int)fp8;
- (void)popToViewController:(id)fp8;
- (void)popToViewController:(id)fp8 transition:(int)fp12;
- (BOOL)snapBackForIdentifier:(id)fp8 userInfo:(id)fp12;
- (BOOL)snapBackForIdentifier:(id)fp8 userInfo:(id)fp12 transition:(int)fp16;
- (void)presentOverlayViewController:(id)fp8;
- (void)dismissOverlayViewController;
- (void)dismissOverlayViewControllerWithTransition:(int)fp8;
- (id)overlayViewController;
- (void)_toggleEditingWithAnimation:(BOOL)fp8;
- (void)setEditing:(BOOL)fp8 animate:(BOOL)fp12;
- (BOOL)isEditing;
- (void)updateNavigationTitle:(id)fp8;
- (void)updateAllNavigationTitles;
- (void)_updateTitleForNavigationItem:(id)fp8 viewController:(id)fp12;
- (void)updateNavigationButtonsWithAnimation:(BOOL)fp8;
- (void)_displayNavigationButtonsForViewController:(id)fp8 withPreviousViewController:(id)fp12 animate:(BOOL)fp16;
- (void)updateAccessoryView;
- (void)navigationBar:(id)fp8 poppedItem:(id)fp12;
- (void)navigationBar:(id)fp8 buttonClicked:(int)fp12;
- (id)buttonBarBadge;
- (id)defaultPNGName;

@end
