//
//  NSView+GSExtensions.m
//  GNUstepGUI
//
//  Created by C.W. Betts on 4/1/17.
//  Copyright © 2017 C.W. Betts. All rights reserved.
//

#import "NSView+GSExtensions.h"
#import <GNUstepBase/GNUstepBase.h>

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

- (void) removeSubview: (NSView*)aView
{
	id view;
	/*
	 * This must be first because it invokes -resignFirstResponder:,
	 * which assumes the view is still in the view hierarchy
	 */
	for (view = [_window firstResponder];
		 view != nil && [view respondsToSelector: @selector(superview)];
		 view = [view superview])
	{
		if (view == aView)
		{
	  [_window makeFirstResponder: _window];
	  break;
		}
	}
	[self willRemoveSubview: aView];
	aView->_superview = nil;
	[aView viewWillMoveToWindow: nil];
	[aView viewWillMoveToSuperview: nil];
	[aView setNextResponder: nil];
	RETAIN(aView);
	[_subviews removeObjectIdenticalTo: aView];
	[aView setNeedsDisplay: NO];
	[aView viewDidMoveToWindow];
	[aView viewDidMoveToSuperview];
	RELEASE(aView);
}
@end
