//
//  TLMAccelerometerEvent.h
//  MyoKit
//
//  Copyright (C) 2013 Thalmic Labs Inc.
//  Confidential and not for redistribution. See LICENSE.txt.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKMath.h>

@class TLMMyo;

/**
   Represents the current accelerometer values reported by a TLMMyo's accelerometer. Units are in Gs.
 */
@interface TLMAccelerometerEvent : NSObject <NSCopying>

/**
   The TLMMyo associated with the acceleration event.
 */
@property (nonatomic, weak, readonly) TLMMyo *myo;

/**
   A vector representing the TLMMyo's acceleration (in Gs).
 */
@property (nonatomic, readonly) GLKVector3 vector;

/**
   The timestamp associated with the acceleration event.
 */
@property (nonatomic, strong, readonly) NSDate *timestamp;

@end
