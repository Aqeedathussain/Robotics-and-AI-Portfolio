# Grasp Point Prediction — Cornell Grasping Dataset (ResNet-50)

## Overview

This project implements a deep learning model for predicting grasp points on objects using the Cornell Grasping Dataset. The model uses a pretrained ResNet-50 backbone to identify optimal grasping locations and orientations for robotic manipulation.

## Project Objective

The goal is to train a neural network that can predict where a robotic gripper should grasp an object to successfully pick it up. The model outputs grasp parameters (center position, angle, width, and height) that define a rectangular grasp region.

## Dataset

- **Dataset**: Cornell Grasping Dataset
- **Total Images**: 896
- **Image Format**: RGB images with accompanying grasp labels
- **Label Format**: Rectangular grasps defined by 4 corner points (x, y coordinates)
- **File Pattern**: 
  - Images: `pcdXXXXr.png` (RGB images)
  - Labels: `pcdXXXXcpos.txt` (grasp coordinates)

## Data Split

- **Training Set**: 807 images (90%)
- **Validation Set**: 89 images (10%)

## Model Architecture

### GraspModel (ResNet-50 based)

```
Input: 224×224 RGB Image
  ↓
ResNet-50 Backbone (Pretrained on ImageNet)
  ↓
Custom FC Head:
  - Linear(2048 → 512)
  - ReLU
  - Dropout(0.3)
  - Linear(512 → 6)
  ↓
Output: 6-dimensional vector [x, y, cos(2α), sin(2α), w, h]
```

### Output Parameters

The model predicts 6 values for each grasp:
- **x, y**: Normalized grasp center coordinates (0-1)
- **cos(2α), sin(2α)**: Normalized angle representation (angle repeats every 180°)
- **w, h**: Normalized grasp width and height (0-1)

## Key Features

### Data Augmentation
- Random rotation: ±30°
- Random horizontal flipping
- Automatic retry if augmentation moves all grasps out of view

### Image Preprocessing
- Center crop: 480×480 pixels from 640×480 image
- Resize to 224×224 for ResNet-50
- Normalization using ImageNet statistics:
  - Mean: [0.485, 0.456, 0.406]
  - Std: [0.229, 0.224, 0.225]

### Accuracy Metric (Cornell Rule)
A predicted grasp is considered **correct** if:
- Angle difference from ground truth: **< 30°**
- Intersection over Union (IoU): **> 0.25**

## Hyperparameters

| Parameter | Value |
|-----------|-------|
| Image Size | 224×224 |
| Crop Size | 480×480 |
| Batch Size | 32 |
| Learning Rate | 1e-4 |
| Optimizer | Adam |
| Loss Function | MSE Loss |
| Epochs | 40 |
| Validation Split | 10% |
| Random Seed | 42 |

## Training Results

- **Best Validation Accuracy**: 59.1%
- **Training Loss Trend**: Decreasing from 0.3455 to 0.1063
- **Best Model Saved**: Epoch 31 with 59.1% accuracy

### Training Progress (Selected Epochs)
| Epoch | Loss | Validation Accuracy |
|-------|------|-------------------|
| 1 | 0.3455 | 12.5% |
| 5 | 0.1336 | 34.1% |
| 10 | 0.1012 | 39.8% |
| 12 | 0.0977 | 52.3% |
| 31 | 0.1060 | 59.1% ✓ |
| 40 | 0.1063 | 54.5% |

## Installation & Requirements

### Dependencies
```bash
pip install torch torchvision torchaudio
pip install opencv-python
pip install numpy
pip install matplotlib
pip install shapely
pip install google-colab  # Only if running on Google Colab
```

### PyTorch Installation (GPU)
```bash
pip install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cu118
```

## Usage

### 1. Prepare Dataset
- Upload Cornell Grasping Dataset to Google Drive
- Set `DATA_ROOT` to point to dataset location
- Ensure images follow naming pattern: `pcdXXXXr.png` and labels: `pcdXXXXcpos.txt`

### 2. Mount Google Drive
```python
from google.colab import drive
drive.mount("/content/drive")
```

### 3. Train the Model
```python
# Run all cells in order from Step 1 to Step 13
# Model checkpoint will be saved to DRIVE_DIR
```

### 4. Evaluate & Visualize
```python
# Step 14: View training graphs
# Step 15: Test on validation images and visualize predictions
```

### 5. Load Trained Model
```python
model = GraspModel(pretrained=True)
model.load_state_dict(torch.load(CKPT))
model.eval()
```

## File Structure

```
Grasp_point_Prediction.ipynb
├── Step 1: Import libraries
├── Step 2: Settings (hyperparameters)
├── Step 3: Connect Google Drive
├── Step 4: Load dataset
├── Step 5: Read grasp labels
├── Step 6: Grasp conversion functions
├── Step 7: Dataset class & preprocessing
├── Step 8: Train/validation split
├── Step 9: Visualize samples
├── Step 10: Build ResNet-50 model
├── Step 11: Accuracy metric (Cornell rule)
├── Step 12: Loss & optimizer
├── Step 13: Training loop
├── Step 14: Training graphs
└── Step 15: Test predictions
```

## Key Functions

### Grasp Conversion
- `rect_to_grasp(corners)`: Convert 4 corner points to grasp parameters
- `grasp_to_rect(x, y, angle, w, h)`: Convert grasp parameters to rectangle
- `encode(grasp)`: Normalize grasp for network input
- `decode(vec)`: Denormalize network output to grasp parameters

### Data Processing
- `read_grasps(txt_path)`: Load grasp labels from file
- `prepare_image(path, augment)`: Load, augment, and preprocess images
- `GraspDataset`: PyTorch Dataset class for loading image-grasp pairs

### Evaluation
- `iou(g1, g2)`: Compute Intersection over Union
- `angle_gap(a, b)`: Compute angular difference accounting for 180° periodicity
- `is_correct(pred, true_grasps)`: Check if prediction satisfies Cornell rule

## Model Performance

### Strengths
✓ Reasonable validation accuracy (59.1%)
✓ Consistent convergence during training
✓ Effective use of pretrained weights
✓ Robust grasp evaluation metric

### Potential Improvements
- Data augmentation strategies (brightness, scale, noise)
- Hyperparameter tuning (learning rate scheduling)
- Ensemble methods for better predictions
- Multi-grasp prediction per image
- Region proposal networks for grasp detection

## Visualization

The notebook includes visualizations for:
- **Ground truth grasps**: 4 sample images with annotated grasp rectangles
- **Training curves**: Loss and validation accuracy over epochs
- **Predictions**: Model predictions on validation images with true labels

## Output

Trained model checkpoint: `resnet50_grasp_best.pth`
- Location: Google Drive (`/content/drive/MyDrive/grasp_project/`)
- Can be loaded for inference or fine-tuning

## References

- Cornell Grasping Dataset: https://www.cs.cornell.edu/~asaxena/datasets/
- ResNet Paper: https://arxiv.org/abs/1512.03385
- PyTorch Documentation: https://pytorch.org/docs/

## Author

**Aqeedathussain**

## License

This project is part of the Robotics and AI Portfolio.

---

## Notes

- Recommended to run on GPU (CUDA 11.8+) for faster training
- Training takes approximately 30-60 minutes on GPU
- The model learns the grasp representation effectively despite the small dataset
- Best results are typically achieved around epoch 30-35
