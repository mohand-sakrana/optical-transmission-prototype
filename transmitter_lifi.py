import tkinter as tk
import serial

def send_data():                            # Function to send data to Arduino
    data = text_area.get("1.0", "end-1c")   # Get text from the text area
    # text_area.delete('1.0','end')         # delete text after press on button
    serial_port.write(data.encode())        # Write data to the serial port
    print(data.encode())

# Create the main window
root = tk.Tk()
root.resizable(False, False)
root.geometry("600x500")
root.title("Transimitter side")             # name of page 
root.configure(background='#0C0C2E')  

# Create text area
text_area = tk.Text(root) 
text_area.pack(padx=10,pady=10)
text_area.configure(background='white', font=11 , fg='#0C0C2E')

# Create send button
send_button = tk.Button(root, text="Send",fg='#0C0C2E', bg='white', font=('Arial', 13, 'bold') ,command=send_data ,relief="raised" )
send_button.pack(pady=5)

# Initialize serial port
serial_port = serial.Serial('COM5', 9600)  # Change 'COM6' to the appropriate port and baudrate

# Start the GUI event loop
root.mainloop()