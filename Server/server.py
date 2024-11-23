from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/api/data', methods=['POST'])
def receive_data():
    """Endpoint to receive JSON data from the IoT device."""
    if request.is_json:
        data = request.get_json()
        print("Received data:", data)  
        
        
        return jsonify({"message": "Data received successfully!", "data": data}), 200
    else:
        return jsonify({"error": "Request must be JSON"}), 400

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000) 