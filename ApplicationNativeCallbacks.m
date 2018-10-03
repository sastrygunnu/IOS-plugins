#import <Intents/Intents.h>
void konyNC_on_app_start()
{
    [INPreferences requestSiriAuthorization:^(INSiriAuthorizationStatus status) {
        if(status == INSiriAuthorizationStatusAuthorized)
        {
            NSLog(@"********************** Inside konyNC_on_app_start -> Siri Authorization GRANTED....");
        }
        else
        {
            NSLog(@"********************** Inside konyNC_on_app_start -> Siri Authorization NOT granted....");
        }
    }];
}

void konyNC_on_app_active()
{
}

void konyNC_on_app_inactive()
{
}

void konyNC_on_app_foreground()
{
}

void konyNC_on_app_background()
{
}


