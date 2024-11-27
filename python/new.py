import cv2

# Load ảnh hoặc video
img = cv2.imread('/Users/dinhductam/Desktop/vo-su-nguyen-van-dung-voi-chiec-dai-trang-3171.jpg')
#img = cv2.VideoCapture(0)  # Sử dụng webcam

# Tải bộ phân loại Haar cascade
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

# Chuyển ảnh thành grayscale
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Phát hiện khuôn mặt
faces = face_cascade.detectMultiScale(gray, 1.1, 4)

# Vẽ hình chữ nhật quanh khuôn mặt
for (x, y, w, h) in faces:
    cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)

# Hiển thị kết quả
cv2.imshow('img', img)
cv2.waitKey(0)
cv2.destroyAllWindows()