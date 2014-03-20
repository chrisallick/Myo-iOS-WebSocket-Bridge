//
//  TLMRotationRateData.h
//  MyoKit
//
//  Copyright (C) 2013 Thalmic Labs Inc.
//  Confidential and not for redistribution. See LICENSE.txt.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKMath.h>

@class TLMMyo;

/**
   Represents the current gyroscope values reported by a TLMMyo's gyroscope. Units are in rad/s.
 */
@interface TLMGyroscopeEvent : NSObject <NSCopying>

/**
   The TLMMyo associated with the gyroscope event.
 */
@property (nonatomic, weak, readonly) TLMMyo *myo;

/**
   A vector representing the TLMMyo's gyroscope values (in rad/s).
 */
@property (nonatomic, readonly) GLKVector3 vector;

/**
   The timestamp associated with the gyroscope event.
 */
@property (nonatomic, strong, readonly) NSDate *timestamp;

@end
