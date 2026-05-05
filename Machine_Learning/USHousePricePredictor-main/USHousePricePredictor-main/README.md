# USHousePricePredictor

## Overview
This repository features a machine learning model using Random Forest regression to predict house prices in the US. It utilizes a dataset from Kaggle containing features like square footage, bedrooms, location, and more. The project demonstrates end-to-end ML workflow: data cleaning, model training, hyperparameter tuning, and performance evaluation. Built in Python for educational and predictive analytics purposes.

## Features
- **Data Preprocessing**: Handles missing values, encoding categorical variables, and scaling using Pandas and Scikit-learn.
- **Model Implementation**: Random Forest regressor with cross-validation for accurate price predictions.
- **Evaluation**: Metrics include Mean Absolute Error (MAE), Root Mean Squared Error (RMSE), and R² score.

## Installation
1. Clone the repository: `git clone https://github.com/your-username/USHousePricePredictor.git`
2. Install dependencies: `pip install -r requirements.txt`
3. Run the notebook or script: Open in Jupyter/Colab and execute the cells.

## Usage
- Download the Kaggle dataset (e.g., `usa-housing.csv`) and place it in `/data/`.
- Train the model: Run the training script or notebook.
- Predict prices: Use the model with inputs like `predict_price(sqft=2000, bedrooms=3, location='CA')`.
- Output example: "Predicted Price: $450,000 (Confidence Interval: ±$20,000)"

## Dataset
Sourced from Kaggle's US Housing dataset (included or linked in `/data/`). Ensure compliance with Kaggle's terms for usage. For custom predictions, adapt with your own data.
