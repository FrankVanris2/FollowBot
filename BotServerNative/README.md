
# Installation

## Configure the environment variables

The React Native tools require some environment variables to be set up in order to build apps with native code.

1) Open the Windows Control Panel.
2) Search for 'edit environment variables' and click on 'Edit environment variables for your account'
3) In 'User Variables' click on New... and create the variables ANDROID_HOME and ANDROID_SDK_ROOT with
value C:\Android\sdk.
4) Select the Path variable and click on Edit. A new window pops up.
5) Add the following path: C:\Android\sdk\cmdline-tools\latest\bin.
6) Close the 'Edit environment variables' windows.

## Install Android SDK

Go to the web page https://developer.android.com/studio/index.html#command-line-tools-only and download
the windows version. Unzip the version into C:\Android\sdk. In 'cmdline-tools'
create the directory 'latest' and move all other subdirectories and files into 'latest'.

Open a command line window (not powershell!) and navigate to C:\Android\sdk\cdmdline-tools\latest\bin.

Run the following to download the latest android package:

```cmd
sdkmanager "platforms;android-25"
```

Update everything

```cmd
sdkmanager --update
```

## Build android version

Navigate to the BotServerNative directory and give the command:

```cmd
npm i
```

Connect your device to the computer and then give the command:

```cmd
npx react-native build-android
```

# Run the development environment

## Start the Metro Server

To start Metro go to the FollowBotNative directory and type:

```cmd
npm run android
```

When (finally) the menu comes up select 'a' for android. If there is no 'a' available then select 'r'
for reload app. This will install the application on the device. Any updates to the code are directly
reflected in the application.

# Debugging the application

Shake the device and a menu comes up. Select the 'Open Devtools' and the Devtools window will pop up.
