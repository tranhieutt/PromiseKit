#import <CoreLocation/CLLocationManager.h>
#import <PromiseKit/fwd.h>

/**
 To import the `CLLocationManager` category:

    pod "PromiseKit/CLLocationManager"

 Or you can import all categories on `CoreLocation`:

    pod "PromiseKit/CoreLocation"
*/
@interface CLLocationManager (PromiseKit)

/**
 Determines the device’s location waiting until the positional accuracy
 of the measured locations is better than 500 meters.

 If your app has not yet asked the user for locational determination
 permissions, PromiseKit calls `+requestWhenInUseAuthorization`, if
 you need always permissions, you must call this yourself before
 any use of this method, or the promise will be rejected.

 @return A promise that thens two parameters:
 1. The most recent `CLLocation`.
 2. An array of all recent `CLLocations`.
*/
+ (PMKPromise *)promise;


/**
 0.2.4.6.8.0.2.4.6.8.0.2.4.6.8.0.2.4.6.8.0.2.4.6.8.0.2.4.6.8.0.2.4.6.8.0.2
 Determines the device’s location using the provided block to determine
 which locations are acceptable.

 With this variant you can wait for good accuracy or accept bad
 accuracy (at your own determination) if the `CLLocationManager`
 is taking too long. For example, the user is not outside so you
 will never get 10 meter accuracy, but it would be nice to wait
 a little just in case.

 @see +promise
*/
+ (PMKPromise *)until:(BOOL(^)(CLLocation *))isLocationGoodBlock;

@end
