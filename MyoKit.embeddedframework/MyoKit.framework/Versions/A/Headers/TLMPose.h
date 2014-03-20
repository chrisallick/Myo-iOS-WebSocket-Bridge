//
//  TLMPose.h
//  MyoKit
//
//  Copyright (C) 2013 Thalmic Labs Inc.
//  Confidential and not for redistribution. See LICENSE.txt.
//

#import <Foundation/Foundation.h>

@class TLMMyo;

//---------
// TLMPose
//---------

/** Represents a hand pose detected by a TLMMyo. */
@interface TLMPose : NSObject <NSCopying>

/**
   Represents different hand poses.
 */
    typedef NS_ENUM (NSInteger, TLMPoseType) {
    TLMPoseTypeNone, /**< Default pose type when no pose is being made.*/
    TLMPoseTypeFist, /**< Clenching fingers together to make a fist.*/
    TLMPoseTypeWaveIn, /**< Turning your palm towards yourself.*/
    TLMPoseTypeWaveOut, /**< Turning your palm away from yourself.*/
    TLMPoseTypeFingersSpread, /**< Spreading your fingers and extending your palm.*/
    TLMPoseTypeTwistIn /**< Twist your wrist in towards yourself.*/
};

/** The TLMMyo posting the pose. */
@property (nonatomic, weak, readonly) TLMMyo *myo;

/** The pose being recognized. */
@property (nonatomic, readonly) TLMPoseType type;

/** The time the pose was recognized. */
@property (nonatomic, strong, readonly) NSDate *timestamp;

@end
