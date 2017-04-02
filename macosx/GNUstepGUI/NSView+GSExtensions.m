//
//  NSView+GSExtensions.m
//  GNUstepGUI
//
//  Created by C.W. Betts on 4/1/17.
//  Copyright © 2017 C.W. Betts. All rights reserved.
//

#import "NSView+GSExtensions.h"

@implementation NSView (GSExtensions)
/**
 * GNUstep addition ... a conveninece method to insert a view in the
 * key view chain before the receiver, using the -previousKeyView and
 * -setNextKeyView: methods.
 */
- (void) setPreviousKeyView: (NSView *)aView
{
	NSView	*p = [self previousKeyView];
	
	if (aView == p || aView == self)
	{
		return;
	}
	[p setNextKeyView: aView];
	[aView setNextKeyView: self];
}

@end
