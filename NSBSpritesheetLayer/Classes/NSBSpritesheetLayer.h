//
//  NSBSpritesheetLayer.h
//  NSBSpritesheetLayer
//
//  Created by Nacho Soto on 8/11/13.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

@class NSBSpritesheet;

@interface NSBSpritesheetLayer : CALayer

- (id)initWithSpritesheet:(NSBSpritesheet *)spritesheet framesPerSecond:(NSUInteger)framesPerSecond;

- (BOOL)isAnimating;

/**
 * @discussion return NO if the animation was already in progress
 */
- (BOOL)animate;
- (BOOL)animateWithCompletionBlock:(void(^)(BOOL finished))completionBlock;

- (void)stop;

/**
 * @discussion the animation plays back and will be completed when going back to the first frame
 */
@property (nonatomic, readwrite, assign) BOOL autoreverses;

/**
 * @discussion can be set after `animate` has been called. It will be reset to nil when the animation has finished.
 */
@property (nonatomic, readwrite, copy) void (^completionBlock)(BOOL completed);

@end
