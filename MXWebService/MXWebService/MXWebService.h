//
//  MXWebService.h
//  MXWebService
//
//  Created by lly on 16/8/15.
//  Copyright © 2016年 meixin. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for MXWebService.
FOUNDATION_EXPORT double MXWebServiceVersionNumber;

//! Project version string for MXWebService.
FOUNDATION_EXPORT const unsigned char MXWebServiceVersionString[];

#import "MXGomePlusConverter.h"
#import "MXDataConverterFactory.h"
#import "MXDictionryConvertable.h"
#import "MXPublicParamsFactory.h"
#import "MXWebClient.h"


#define MXWebRequest(aprotocol) ((NSObject<aprotocol> *)[MXWebClientInstance create:@protocol(aprotocol)])

#define MXWebRequestSpecial(aprotocol,pubicParamsType,pubicParamsDic) [MXWebClientInstance create:@protocol(aprotocol) publicParamsType:pubicParamsType publicParamsDic:pubicParamsDic]


#ifdef MX_SWIFT_COMPAT
#define MX_SUCCESS_BLOCK(type) (void (^ __nonnull)(type __nullable result, NSURLResponse* __nullable response))
#define MX_FAIL_BLOCK(type) (void (^ __nonnull)(type __nullable errorMessage, NSURLResponse* __nullable response, NSError* __nullable error))
#else
#define MX_SUCCESS_BLOCK(type) (void (^)(type result, NSURLResponse *response))
#define MX_FAIL_BLOCK(type) (void (^)(type errorMessage, NSURLResponse *response, NSError* error))
#endif

#define GET(unused)		required
#define POST(unused)	required
#define DELETE(unused)	required
#define PUT(unused)		required
#define HEAD(unused)	required
#define PATCH(unused)	required


#define Body(unused)	required
#define Headers(...)	required

//body type default is formData
#define FormData        required
#define FormUrlEncoded   required
#define FormRaw         required

//Cache time example: Cache(1D) Cache(1H)
#define Cache(unused)   required

@protocol MXDataConverterFactoryDelegate;


@protocol MXWebService <NSObject>

- (NSURL*)endPoint;
- (NSURLSession*)urlSession;
- (NSDictionary*)methodDescriptions;
- (id<MXDataConverterFactoryDelegate>)converterFactory;

@optional
@property (nonatomic,assign) MXPublicParamsType publicParamsType;

@end


