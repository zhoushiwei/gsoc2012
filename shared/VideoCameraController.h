//
//  ImageCaptureViewController.h
//  IntroCamera
//
//  Created by Eduard Feicho on 1/06/12.
//  Copyright 2012 Eduard Feicho. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>


@class VideoCameraController;

@protocol VideoCameraControllerDelegate <NSObject>

- (void)videoCameraViewController:(VideoCameraController*)videoCameraViewController capturedImage:(UIImage *)image;
- (void)videoCameraViewControllerDone:(VideoCameraController*)videoCameraViewController;
- (UIImage*)processImage:(UIImage*)image;
- (BOOL)allowMultipleImages;
- (BOOL)allowPreviewLayer;
- (UIView*)getPreviewView;

@end



@interface VideoCameraController : NSObject<AVCaptureVideoDataOutputSampleBufferDelegate>
{
	BOOL isUsingFrontFacingCamera;
	
	BOOL canTakePicture;
	BOOL captureSessionLoaded;

	AVCaptureSession* captureSession;
	AVCaptureStillImageOutput *stillImageOutput;
	
	dispatch_queue_t videoDataOutputQueue;
	AVCaptureVideoDataOutput *videoDataOutput;
	
	AVCaptureVideoPreviewLayer *captureVideoPreviewLayer;
	AVCaptureConnection* videoCaptureConnection;
	UIDeviceOrientation currentDeviceOrientation;
	
	BOOL running;
}

@property (nonatomic, assign) id<VideoCameraControllerDelegate> delegate;
@property (nonatomic, readonly) BOOL running;


- (void)start;
- (void)stop;
- (void)switchCameras;




@end
