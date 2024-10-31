from flask import Flask, request, jsonify
import serial

app = Flask(__name__)

# Set up serial connection to Arduino (update the port to match your system)
arduino = serial.Serial('/dev/ttyUSB0', 9600)  # Adjust the port as necessary

@app.route('/led', methods=['GET'])
def control_led():
    state = request.args.get('state')
    if state not in ['on', 'off']:
        return jsonify({'error': 'Invalid state'}), 400

    try:
        # Send command to Arduino
        arduino.write((state + '\n').encode())
        return jsonify({'status': f'LED turned {state}'}), 200
    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
