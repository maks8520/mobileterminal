#import "PieView.h"
#import <UIKit/UIView-Geometry.h>
#import <UIKit/UIAnimator.h>
#import <UIKit/UITransformAnimation.h>
#import <UIKit/UIAlphaAnimation.h>
#import <UIKit/UIView-Rendering.h>

@implementation PieView
-(BOOL)ignoresMouseEvents { return YES; }

-initWithFrame:(CGRect)frame {
    if ((self = [super initWithFrame:frame])) {
        visibleFrame = frame;
        hiddenFrame = CGRectMake(frame.origin.x+(frame.size.width/2.0f), frame.origin.y+(frame.size.height/2.0f), 1.0f, 1.0f);
        location = CGPointMake(frame.origin.x+(frame.size.width*0.5f), frame.origin.y+(frame.size.height*0.5f));
        _visible = YES;
    }
    return self;
}

-(void)showAtPoint:(CGPoint)p {
    if (!_visible) {
        _visible = YES;
    visibleFrame.origin.x = 0.0f;//p.x - (int)(visibleFrame.size.width / 2.0f);
    visibleFrame.origin.y = 0.0f;//p.y - (int)(visibleFrame.size.height / 2.0f);
    //hiddenFrame = CGRectMake(visibleFrame.origin.x+(visibleFrame.size.width/2.0f), visibleFrame.origin.y+(visibleFrame.size.height/2.0f), 1.0f, 1.0f);
    p.x = (int)(p.x - visibleFrame.size.width*0.5f);
    p.y = (int)(p.y - visibleFrame.size.height*0.5f);;
    location = p;
    [self setTransform:CGAffineTransformMake(1,0,0,1,0,0)];
//    CGRect frame = [self frame];
//    frame.origin.x = 0.0f;//(float)(p.x - (int)(frame.size.width / 2.0f));
//    frame.origin.y = 0.0f;// (float)(p.y - (int)(frame.size.height / 2.0f));
    [self setFrame: visibleFrame];
        [self setTransform:CGAffineTransformMake(0.01f,0,0,0.01f,0,480)];
        [self setAlpha: 0.0f];
        //[self setFrame:hiddenFrame];
        UITransformAnimation *scaleAnim = [[UITransformAnimation alloc] initWithTarget: self];
        [scaleAnim setStartTransform: CGAffineTransformMake(0.01f,0,0,0.01f,p.x,p.y)];
        [scaleAnim setEndTransform: CGAffineTransformMake(1,0,0,1,p.x,p.y)];
        UIAlphaAnimation *alphaAnim = [[UIAlphaAnimation alloc] initWithTarget: self];
        [alphaAnim setStartAlpha: 0.0f];
        [alphaAnim setEndAlpha: 0.9f];
        UIAnimator *anim = [[UIAnimator alloc] init];
        [anim addAnimation:scaleAnim withDuration:0.15f start:YES]; 
        [anim addAnimation:alphaAnim withDuration:0.15f start:YES];
        //[self setTransform:CGAffineTransformMake(1,0,0,1,0,0)];
        //[self setFrame:visibleFrame];
    }
}

-(void)hide { [self hideSlow:NO]; }

-(void)hideSlow:(BOOL)slow {
    if (_visible) {
        //[self setTransform:CGAffineTransformMake(1,0,0,1,0,0)];
        //[self setFrame:visibleFrame];
        UITransformAnimation *scaleAnim = [[UITransformAnimation alloc] initWithTarget: self];
        [scaleAnim setStartTransform: CGAffineTransformMake(1,0,0,1,location.x,location.y)];
        [scaleAnim setEndTransform: CGAffineTransformMake(0.01f,0,0,0.01f,location.x,location.y)];
        UIAlphaAnimation *alphaAnim = [[UIAlphaAnimation alloc] initWithTarget: self];
        [alphaAnim setStartAlpha: 0.9f];
        [alphaAnim setEndAlpha: 0.0f];
        float duration = slow ? 1.0f : 0.25f;
        UIAnimator *anim = [[UIAnimator alloc] init];
        if (!slow) [anim addAnimation:scaleAnim withDuration:duration start:YES]; 
        [anim addAnimation:alphaAnim withDuration:duration start:YES];
        _visible = NO;
    }
}
@end