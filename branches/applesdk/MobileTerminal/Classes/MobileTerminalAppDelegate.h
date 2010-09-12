// MobileTerminalAppDelegate.h
// MobileTerminal

#import <UIKit/UIKit.h>
#import "MobileTerminalViewController.h"
#import "Preferences/PreferencesViewController.h"

@class Settings;

@interface MobileTerminalAppDelegate : NSObject <UIApplicationDelegate,
                                                 MobileTerminalInterfaceDelegate> {
@private
  UIWindow *window;
  UINavigationController *navigationController;
  MobileTerminalViewController *terminalViewController;
  Settings* settings;
  PreferencesViewController *preferencesViewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet UINavigationController *navigationController;
@property (nonatomic, retain) IBOutlet MobileTerminalViewController *terminalViewController;
@property (nonatomic, retain) IBOutlet PreferencesViewController *preferencesViewController;

- (void)preferencesButtonPressed;
- (void)preferencesDonePressed:(id)sender;

@end
