import threading
import tkinter as tk
import serial
# Create serial connection to Arduino
ser = serial.Serial('COM6', 9600)                # Adjust the COM port and baud rate accordingly

def read_data():                                 # Function to read data from Arduino
    while True:
        data = ser.read()                        # Read data from Arduino 
        text_area.insert(tk.END, data )          # print data in text area

def refresh_data():                              # Function to refresh data
    text_area.delete('1.0', tk.END)              # Clear the text area

# Create GUI window
root = tk.Tk()
root.resizable(False, False)
root.geometry("600x500")
root.title("Receiver side")
root.configure(background='#0C0C2E')

# Create text area to display data
text_area = tk.Text(root)
text_area.pack(padx=10, pady=10)
text_area.configure(background='white', font=11 , fg='#0C0C2E')

# Create refresh button
refresh_button = tk.Button(root, text="Refresh",fg='#0C0C2E',bg='white', font=('Arial', 13, 'bold') , command=refresh_data)
refresh_button.pack(pady=5)

# Start a separate thread to continuously read data from the serial port
thread = threading.Thread(target=read_data)
thread.start()

# Start the GUI event loop
root.mainloop()
