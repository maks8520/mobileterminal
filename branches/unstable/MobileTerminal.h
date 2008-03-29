//
// MobileTerminal.h
// Terminal

#import <UIKit/UIKit.h>
#import <GraphicsServices/GraphicsServices.h>
#import "Constants.h"
#import "Log.h"

@class PTYTextView;
@class ShellKeyboard;
@class SubProcess;
@class VT100Screen;
@class VT100Terminal;
@class GestureView;
@class PieView;
@class PreferencesController;
@class MobileTerminal;
@class Settings;

#define MAXTERMINALS 4

//_______________________________________________________________________________

@interface MobileTerminal : UIApplication
{
  UIWindow	  					*	window;

  ShellKeyboard					* keyboardView;	
	UITransitionView			* contentView;
  UIView								* mainView;

	UIView								* activeView;

  GestureView						* gestureView;
	
	PreferencesController	* preferencesController;
	
  NSMutableArray				* processes;
  NSMutableArray				* screens;
  NSMutableArray				* terminals;
  NSMutableArray				* textviews;
  NSMutableArray				* scrollers;

  Settings              * settings;
	
  int numTerminals;
  int activeTerminal;	
	int lastTerminal;

  BOOL controlKeyMode;
  BOOL keyboardShown;
	BOOL landscape;
	int  degrees;
}

@property BOOL landscape;
@property int  degrees;
@property BOOL controlKeyMode;
@property (readonly) UIView				* activeView;
@property (readonly) UIView				* mainView;
@property (readonly) PTYTextView	* textView;

+ (MobileTerminal*) application;

- (void) applicationDidFinishLaunching:(NSNotification *)aNotification;
- (void) applicationSuspend:(GSEvent *)event;
- (void) applicationResume:(GSEvent *)event;

- (void) handleStreamOutput:(const char*)c length:(unsigned int)len identifier:(int)tid;
- (void) handleKeyPress:(unichar)c;

- (void) updateStatusBar;
- (void) updateFrames:(BOOL)needsRefresh;
- (void) setOrientation:(int)degrees;
- (CGPoint) viewPointForWindowPoint:(CGPoint)point;

-(SubProcess*) activeProcess;
-(VT100Screen*) activeScreen;
-(VT100Terminal*) activeTerminal;
-(NSArray*) textviews;

-(UIView*) mainView;
-(UIView*) activeView;
-(PTYTextView*) textView;
-(UIScroller*) textScroller;

- (void) togglePreferences;

// Invoked by GestureMenu
- (void) hideMenu;
- (void) showMenu:(CGPoint)point;
- (void) handleInputFromMenu:(NSString*)input;
- (void) toggleKeyboard;

// Invoked by SwitcherMenu
- (void) prevTerminal;
- (void) nextTerminal;
- (void) createTerminals;
- (void) destroyTerminals;
- (void) setActiveTerminal:(int)active;
- (void) setActiveTerminal:(int)active direction:(int)direction;

@end
