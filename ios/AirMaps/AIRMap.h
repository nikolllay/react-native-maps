/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <MapKit/MapKit.h>
#import <UIKit/UIKit.h>

#import <React/RCTComponent.h>
#import "SMCalloutView.h"
#import "RCTConvert+AirMap.h"
#import "AIRMapCalloutSubview.h"


@class AIRMapCoordinate;
@class AIRMapMarker;

extern const NSTimeInterval AIRMapRegionChangeObserveInterval;
extern const CGFloat AIRMapZoomBoundBuffer;
extern const NSInteger AIRMapMaxZoomLevel;

@interface AIRMap: MKMapView<SMCalloutViewDelegate>

@property (nonatomic, strong) SMCalloutView *calloutView;
@property (nonatomic, strong) UIImageView *cacheImageView;
@property (nonatomic, strong) UIView *loadingView;

@property (nonatomic, copy) NSString *userLocationAnnotationTitle;
@property (nonatomic, assign) BOOL followsUserLocation;
@property (nonatomic, assign) BOOL userLocationCalloutEnabled;
@property (nonatomic, assign) BOOL hasStartedRendering;
@property (nonatomic, assign) BOOL cacheEnabled;
@property (nonatomic, assign) BOOL loadingEnabled;
@property (nonatomic, assign) BOOL handlePanDrag;
@property (nonatomic, assign) BOOL legacyZoomConstraintsEnabled;
@property (nonatomic, strong) UIColor *loadingBackgroundColor;
@property (nonatomic, strong) UIColor *loadingIndicatorColor;
@property (nonatomic, assign) BOOL hasShownInitialLoading;
@property (nonatomic, assign) CGFloat minDelta;
@property (nonatomic, assign) CGFloat maxDelta;
@property (nonatomic, assign) UIEdgeInsets legalLabelInsets;
@property (nonatomic, assign) MKCoordinateRegion initialRegion;
@property (nonatomic, retain) MKMapCamera *initialCamera;
@property (nonatomic, assign) CGFloat minZoom;
@property (nonatomic, assign) CGFloat maxZoom;
@property (nonatomic, assign) CGPoint compassOffset;
@property (nonatomic, assign) UIEdgeInsets mapPadding;

@property (nonatomic, assign) CLLocationCoordinate2D pendingCenter;
@property (nonatomic, assign) MKCoordinateSpan pendingSpan;


@property (nonatomic, assign) BOOL ignoreRegionChanges;

@property (nonatomic, copy) RCTDirectEventBlock onMapReady;
@property (nonatomic, copy) RCTDirectEventBlock onRegionChangeStart;
@property (nonatomic, copy) RCTDirectEventBlock onRegionChange;
@property (nonatomic, copy) RCTDirectEventBlock onRegionChangeComplete;
@property (nonatomic, copy) RCTBubblingEventBlock onPress;
@property (nonatomic, copy) RCTBubblingEventBlock onLongPress;
@property (nonatomic, copy) RCTDirectEventBlock onPanDrag;
@property (nonatomic, copy) RCTDirectEventBlock onDoublePress;
@property (nonatomic, copy) RCTDirectEventBlock onMarkerPress;
@property (nonatomic, copy) RCTDirectEventBlock onMarkerSelect;
@property (nonatomic, copy) RCTDirectEventBlock onMarkerDeselect;
@property (nonatomic, copy) RCTDirectEventBlock onMarkerDragStart;
@property (nonatomic, copy) RCTDirectEventBlock onMarkerDrag;
@property (nonatomic, copy) RCTDirectEventBlock onMarkerDragEnd;

@property (nonatomic, copy) RCTDirectEventBlock onCalloutPress;
@property (nonatomic, copy) RCTDirectEventBlock onUserLocationChange;

- (void)cacheViewIfNeeded;
- (void)beginLoading;
- (void)finishLoading;
- (double)getZoomLevel;
- (NSDictionary *)getMapBoundaries;

- (AIRMapMarker*) markerAtPoint:(CGPoint)point;
- (NSDictionary*) getMarkersFramesWithOnlyVisible:(BOOL)onlyVisible;
- (void)insertReactSubview:(id<RCTComponent>)subview atIndex:(NSInteger)atIndex;
-(void) fitToCoordinates:(NSArray<AIRMapCoordinate*>*) coordinates edgePadding:(UIEdgeInsets) edgeInsets animated:(Boolean) animated;
@end
