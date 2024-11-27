import cv2
from matplotlib import pyplot as plt
cap = cv2.VideoCapture(0)

window_name = 'Live Video'

while True:
    # Đọc một frame từ video
    ret, frame = cap.read()

    # Kiểm tra xem có đọc được frame không
    if not ret:
        print("Không thể đọc được frame")
        break

    # Hiển thị frame
    cv2.imshow(window_name, frame)

    # Chờ phím bất kỳ để thoát
    if cv2.waitKey(1) == ord('q'):
        break

# Giải phóng các tài nguyên
cap.release()
cv2.destroyAllWindows()