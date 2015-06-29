SIMPLE FACEBOOK CONNECT MODULE

Simple FB Connect is a Facebook Connect Integration for Drupal.

It adds to the site:
* A new url : /user/simple-fb-connect
* A tab on /user page pointing to the above url

How it works:
User can click on the "Register / Login with FB" tab on the user login page
You can add a button or link anywhere on the site that points 
to /user/simple-fb-connect. So theming and customizing the button or link 
is very flexible.

When the user opens the /user/simple-fb-connect link, it automatically takes 
user to Facebook and asks for his permission. Once granted the module checks 
the users email. If the email address is found on the Drupal Site, he is logged 
in automatically. Otherwise a new user account is created with the email address
 and the user is logged in.

SETUP:
1) Create a new app on https://developers.facebook.com/apps
This will give you an App ID/API Key and an App Secret
2) Edit the App settings on facebook to enable "Website with Facebook Login"
3) For Site URL, enter the url of your Drupal site 
4) Download Facebook PHP SDK from https://github.com/facebook/facebook-php-sdk/releases
Preferably v 3.2.3. And place the extracted folder in your sites/all/libraries 
directory such that sites/all/libraries/facebook-php-sdk/src/facebook.php and
sites/all/libraries/facebook-php-sdk/readme.md exist
5) Enable Simple FB Connect module and configure at 
admin/config/people/simple-fb-connect
6) Enter your app id and secret key obtained from facebook and save your settings