// MenuView.m
// MobileTerminal

#import "MenuView.h"
#import <QuartzCore/QuartzCore.h>
#import "Preferences/Settings.h"
#import "Preferences/MenuSettings.h"

@implementation MenuView

@synthesize menuTableView;
@synthesize font;
@synthesize menuSettings;
@synthesize delegate;

- (id)initWithCoder:(NSCoder *)decoder
{
  self = [super initWithCoder:decoder];
  if (self != nil) {
    font = [UIFont systemFontOfSize:[UIFont systemFontSize]];
    menuSettings = [[Settings sharedInstance] menuSettings];
  }
  return self;
}

- (void)dealloc {
  [font release];
  [menuSettings release];
  [super dealloc];
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath;  
{
  return [font pointSize] * 1.5f;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
  return [menuSettings count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
  // This currently only supports one section
  if ([indexPath length] != 2 ||
      [indexPath indexAtPosition:0] != 0 ||
      [indexPath indexAtPosition:1] > [menuSettings count]) {
    return nil;
  }
  NSString* itemTitle = [menuSettings itemLabelAtIndex:[indexPath indexAtPosition:1]];
  UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:itemTitle];
  if (cell == nil) {
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:itemTitle];
    cell.textLabel.text = itemTitle;
    cell.textLabel.font = font;
  }
  return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
  NSString* itemCommand = [menuSettings itemCommandAtIndex:[indexPath indexAtPosition:1]];
  [delegate selectedCommand:itemCommand];
}

static const double kAnimationDuration = 0.25f;

- (void)setHidden:(BOOL)isHidden
{
  // TODO(allen): Set the max size of the view based on the total number of
  // menu items.
  if (!isHidden) {
    // When re-displaying the table, start from the top of the menu in a fresh
    // state.
    [menuTableView scrollRectToVisible:CGRectMake(0, 0, 1, 1)
                              animated:NO];
    [menuTableView deselectRowAtIndexPath:[menuTableView indexPathForSelectedRow] animated:NO];
  }
  
  [UIView beginAnimations:NULL context:NULL];
  CATransition *animation = [CATransition animation];
  [animation setDuration:kAnimationDuration];
  if (isHidden) {
    [animation setType:kCATransitionFade];
  } else {
    // Slide up the menu as it appears
    [animation setType:kCATransitionMoveIn];
    [animation setSubtype:kCATransitionFromTop];
  }
  [animation setTimingFunction:[CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut]];	
  [[self layer] addAnimation:animation forKey:@"toggleMenuView"];
  [super setHidden:isHidden];
  [UIView commitAnimations];  
}

@end