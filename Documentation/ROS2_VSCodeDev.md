# Setting Up SSH Keys and Using Visual Studio Code for Remote Development

### Step 1: Generate SSH Keys

1. **Open Command Prompt or PowerShell** on your local machine.
2. **Generate a new SSH key pair** by running the following command:

```bash
ssh-keygen -t rsa
```
3. **Save the key:**
    * When prompted to enter the file in which to save the key, press `Enter` to accept the default location (`C:\Users\your_username\.ssh\id_rsa`).

4. **Enter a passphrase** (optional):
    * You can add a passpharse for additional security or press `Enter` twice to skip this step.

### Step 2: Copy your Public Key to the Raspberry Pi

1. **Display your public key:**
    * Open the public key file and copy its content:
```bash
type C:\Users\your_username\.ssh\id_rsa.pub
```
2. **Connect to your Raspberry Pi via SSH:**
    * Use your password to connect to your Raspberry Pi:
```bash
ssh user@raspberrypi_ip
```
3. **Append the public key to `authorized_keys`:**
    * Run the following commands on your Raspberry Pi:

```bash
mkdir -p ~/.ssh
nano ~/.ssh/authorized_keys
```
<br>

*   Paste your public key into the `authorized_keys` file, Save and exit the editor.
<br><br>

4. **Set the correct permissions:**
```bash
chmod 700 ~/.ssh
chmod 600 ~/.ssh/authorized_keys
```

### Step 3: Install Visual Studio Code on Your Local Machine

1. **Download and Install VSCode:** (If you have not done so already...I don't even know why you are bothering to help and develop this project my gosh).

### Step 4: Install and Configure the Remote-SSH Extension

1. **Open Visual Studio Code** on your local machine.
2. **Install the Remote-SSH extension:**
    * Click on the Extensions icon in the Activity Bar.
    * Search for "Remote-SSH" and install the extension by Microsoft.
3. **Connect to Your Raspberry Pi:**
    * Open the Command Palette (`Ctrl+Shift+P` or `Cmd+Shift+P` on macOS).
    * Type "Remote-SSH: Connect to Host" and selct it.
    * Enter the SSH command to connect:
```bash
ssh user@raspberrypi_ip
```

4. **Open a Remote Folder:**
    * Once connected, open a folder on your Raspberry Pi by selecting "Remote-SSH: Open Folder" from the command Palette.
    * Navigate to the desired directory.

### Step 5: Start Coding

You should now see the remote folder in the VSCode Explorer pane. You can open, edit, and save files on your Raspberry Pi just as if they were on your local machine. Enjoy the full range of VSCode's powerful features, including extensions, debugging, and version control.

