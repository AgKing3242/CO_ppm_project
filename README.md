# IoT-based Environmental Monitoring System with Machine Learning Integration

# Data Collection Phase:
The project began with the collection of environmental data using sensors interfaced with an Arduino microcontroller board. A DHT11 sensor was employed to measure temperature and humidity levels, while an MQ135 sensor was utilized to gauge Carbon Monoxide (CO) concentrations. The Arduino microcontroller facilitated real-time data acquisition, reading sensor values and transmitting them to an ESP01 WiFi module for further processing.

# Data Transmission to ThingSpeak:
Upon collection, the sensor data was transmitted to the ThingSpeak platform via the ESP01 WiFi module. The ESP01 module was configured to connect to a local WiFi network, enabling seamless communication with the ThingSpeak cloud-based IoT platform. This platform served as a repository for the collected data, allowing for easy access, visualization, and analysis.

# Data Preprocessing and Cleaning:
After retrieval from the ThingSpeak platform, the collected data underwent preprocessing and cleaning procedures. This involved handling missing values, removing outliers, and ensuring data consistency and quality. Techniques such as normalization or standardization were applied to make the data suitable for subsequent machine learning analysis.

# Machine Learning Model Selection:
Three distinct machine learning algorithms were chosen for predictive analysis based on their suitability for the dataset: Decision Tree, Random Forest, and a Simple Neural Network. Each algorithm offered unique strengths in handling different types of data and relationships, making them suitable candidates for the environmental monitoring application.

# Model Training and Evaluation:
The dataset was partitioned into training and testing sets to facilitate model training and evaluation. The selected machine learning models were trained using the training dataset and evaluated based on various performance metrics such as accuracy, precision, recall, and F1-score. This process provided insights into the models' predictive capabilities and generalization ability.

# Hyperparameter Tuning:
To further enhance the models' performance, hyperparameter tuning was conducted using GridSearchCV, an optimization technique. This involved exhaustively searching through a specified parameter grid to find the best hyperparameters for each model. By fine-tuning the models, their predictive accuracy and efficiency were improved, ensuring more reliable environmental predictions.

# Results Analysis:
Post-tuning, the performance of each machine learning model was analyzed, and comparisons were drawn based on performance metrics. The most effective model(s) for predicting environmental variables such as temperature, humidity, and CO concentration were identified. These findings provided valuable insights into the efficacy of the IoT-based environmental monitoring system integrated with machine learning.

In conclusion, the project demonstrated the seamless integration of IoT devices, data preprocessing techniques, machine learning algorithms, and hyperparameter tuning to develop an efficient and accurate environmental monitoring system.

# Data Collection Setup

![Image Alt Text](setup.jpg)

