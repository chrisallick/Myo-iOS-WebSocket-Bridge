//
//  TLMOrientationEvent.h
//  MyoKit
//
//  Copyright (C) 2013 Thalmic Labs Inc.
//  Confidential and not for redistribution. See LICENSE.txt.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKMath.h>
#import "TLMEulerAngles.h"

@class TLMMyo;

/**
   Represents the orientation of a TLMMyo. The orientation is represented via a quaternion.
 */
@interface TLMOrientationEvent : NSObject <NSCopying>

/**
   The TLMMyo whose orientation changed.
 */
@property (nonatomic, weak, readonly) TLMMyo *myo;

/**
   Orientation representation as a normalized quaternion.
 */
@property (nonatomic, readonly) GLKQuaternion quaternion;

/**
   The timestamp associated with the orientation.
 */
@property (nonatomic, strong, readonly) NSDate *timestamp;

@end
