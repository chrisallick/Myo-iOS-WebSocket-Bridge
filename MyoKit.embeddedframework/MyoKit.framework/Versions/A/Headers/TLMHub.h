//
//  TLMHub.h
//  MyoKit
//
//  Copyright (C) 2013 Thalmic Labs Inc.
//  Confidential and not for redistribution. See LICENSE.txt.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "TLMMyo.h"

/**
   @defgroup hubNotifications NSNotificationCenter Hub Constants
   These are events sent when the manager detects any change in a TLMMyo's state.
   These can be subscribed to through NSNotificationCenter. They are posted in the default center on the main dispatch
   queue.

   @{
 */

extern NSString *const TLMHubDidConnectDeviceNotification; /**< Posted whenever a TLMMyo connects */
extern NSString *const TLMHubDidDisconnectDeviceNotification; /**< Posted whenever a TLMMyo disconnects */

/** @} */

//--------
// TLMHub
//--------

/**
   The TLMHub singleton manages TLMMyos.
 */
@interface TLMHub : NSObject

/**
   Singleton accessor.
   @return The shared instance of the TLMHub class.
 */
+ (instancetype)sharedHub;

/**
   A snapshot of the list of TLMMyos currently connected to TLMHub.
   @return NSArray containing the connected TLMMyos.
 */
- (NSArray *)myoDevices;

/**
   Searches for any TLMMyo and connects to it. Once connected, the TLMMyo will be paired, and TLMHub
   will try to connect to it as often as it can. Once this method results in the pairing of a Myo, it needs to be called
   again in order to pair with another Myo.
 */
- (void)pairWithAny;

/**
   Calling this method enables pairWithAdjacent mode. When a Myo touches the iOS device, the TLMHub will connect to it.
   If there are too many Myos connected, the first Myo in the myoDevices array is disconnected. Will continue to scan
   until stopPairWithAdjacent is called.
   @see stopPairWithAdjacent
 */
- (void)pairWithAdjacent;

/**
   Stops the TLMHub from pairing with adjacent Myos.
   @see pairWithAdjacent
 */
- (void)stopPairWithAdjacent;

@end
