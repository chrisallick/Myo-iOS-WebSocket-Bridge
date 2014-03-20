//
//  TLMMyo.h
//  MyoKit
//
//  Copyright (C) 2013 Thalmic Labs Inc.
//  Confidential and not for redistribution. See LICENSE.txt.
//

#import <CoreBluetooth/CoreBluetooth.h>
#import <UIKit/UIKit.h>
#import "TLMOrientationEvent.h"
#import "TLMAccelerometerEvent.h"
#import "TLMPose.h"

//---------------
// Notifications
//---------------

/**
   @defgroup deviceNotifications NSNotificationCenter Device Constants
   These are notifications posted by the device when new data is available.
   They are posted by the default center on the main dispatch queue.
   Data associated with the notification can be found in the notification's userInfo dictionary.
   @see deviceNotificationDataKeys.

   @{
 */

/** Posted when a new orientation event is available from a TLMMyo. Notifications are posted at a rate of 50 Hz.

   kTLMKeyOrientationEvent -> TLMOrientationEvent
 */
extern NSString *const TLMMyoDidReceiveOrientationEventNotification;

/** Posted when a new accelerometer event is available from a TLMMyo. Notifications are posted at a rate of 50 Hz.

   kTLMKeyAccelerometerEvent -> TLMAccelerometerEvent
 */
extern NSString *const TLMMyoDidReceiveAccelerometerEventNotification;

/**
   Posted when a new gyroscope event is available from a TLMMyo. Notifications are posted at a rate of 50 Hz.

   kTLMKeyGyroscopeEvent -> TLMGyroscopeEvent
 */
extern NSString *const TLMMyoDidReceiveGyroscopeEventNotification;

/** Posted when a new pose is available from a TLMMyo.

   kTLMKeyPose ->TLMPose
 */
extern NSString *const TLMMyoDidReceivePoseChangedNotification;

/** @} */

/**
   @defgroup deviceNotificationDataKeys NSNotificationCenter Device Data Key Constants
   These keys correspond to data stored in a notifications userInfo dictionary.
   @see deviceNotifications

   @{
 */

/**
   NSNotification userInfo key for a TLMOrientationEvent object.
 */
extern NSString *const kTLMKeyOrientationEvent;

/**
   NSNotification userInfo key for a TLMAccelerometerEvent object.
 */
extern NSString *const kTLMKeyAccelerometerEvent;

/**
   NSNotification userInfo key for a TLMGyroscopeEvent object.
 */
extern NSString *const kTLMKeyGyroscopeEvent;

/**
   NSNotification userInfo key for a TLMPose object.
 */
extern NSString *const kTLMKeyPose;

/** @} */

//-----------
// TLMMyo
//-----------

/**
   Represents a Myo.

   Do not implement NSCopying. You should not be able to copy TLMMyo. Do not subclass. Do not maintain strong
   references to instances of this class, as this can cause unexpected behaviour. TLMHub will keep track of TLMMyos.
 */
@interface TLMMyo : NSObject

/**
   An enum representing the connection state of a TLMMyo.
 */
typedef NS_ENUM (NSInteger, TLMMyoConnectionState) {
    TLMMyoConnectionStateConnected, /**< TLMMyo is connected */
    TLMMyoConnectionStateConnecting, /**< TLMMyo is in the process of connecting */
    TLMMyoConnectionStateDisconnected /**< TLMMyo is not connected */
};

/**
   An enum representing the different types of vibrations a TLMMyo can make.
 */
typedef NS_ENUM (NSInteger, TLMVibrationLength) {
    TLMVibrationLengthShort, /**< A vibration lasting a small amount of time */
    TLMVibrationLengthMedium, /**< A vibration lasting a moderate amount of time */
    TLMVibrationLengthLong /**< A vibration lasting a long amount of time */
};

/**
   The name of the TLMMyo.
 */
@property (nonatomic, strong, readonly) NSString *name;

/**
   The identifier for the TLMMyo. On iOS versions < iOS 7, this property is nil until connected.
 */
@property (nonatomic, strong, readonly) NSString *identifier;

/**
   A snapshot of the current state of the TLMMyo.
 */
@property (nonatomic, readonly) TLMMyoConnectionState state;

- (instancetype)init __attribute__((unavailable("init not available")));

/**
   Presents the trainer into the specified view controller modally, taking up the entire screen. The trainer will dismiss
   itself when it has completed.
   @param viewController The view controller that will present the trainer.
 */
- (void)presentTrainerFromViewController:(UIViewController *)viewController;

/**
   Performs an asynchronous read of the signal strength, passing the resulting value in the result block. The resultBlock
   is executed on the main thread.
   @param resultBlock The resulting signal strength is passed into this block.
 */
- (void)readSignalStrengthWithResult:(void(^)(NSNumber * signalStrength))resultBlock;

/**
   Engage the TLMMyo's built in vibration motor.
   @param length The amount of time the vibration motor will be active.
 */
- (void)vibrateWithLength:(TLMVibrationLength)length;

@end
