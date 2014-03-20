//
//  TLHMViewController.h
//  HelloMyo
//
//  Copyright (c) 2013 Thalmic Labs. All rights reserved.
//  Confidential and not for redistribution. See LICENSE.txt.
//

#import <UIKit/UIKit.h>
#import "SRWebSocket.h"

@interface TLHMViewController : UIViewController <SRWebSocketDelegate> {
    SRWebSocket *_webSocket;
    
    NSString *sid, *username, *roomname, *host;
    
    double last_time;
    
    BOOL connected;
}

@end
