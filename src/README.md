####Neuron.cpp Neuron.h
��������� ������ ������ � ���������� � ������ `Neuron`.

� ������� ������� ���� ������ ����� `weights`, � ����� ��� ������:
����������� `summatory` � ������������� `activation` �������.

��� ���� ������������� ������� ��������� � ���� ��������� �� ������� �
������� � ������������, � ����� ����������� ������������� ���� ������������� �������.

---

####NeuronNet.cpp NeuronNet.h
��������� ������� � ����������� � ���� ������ `NeuronNet`.

� ��������� ���� ������ �������� `layers`, � ������� ��������� ������� ����,
� ����� ������� ��������� ������� ���� `activations`
(�� ��������� ��� ������������� (�������������) ������� `sigmoid`.

����������� `NeuronNet` ��������� � �������� ���������� ���������� ���� `_L`,
������-�����, �������� ������� ���� `nums` � ������� `act_func`, ������� ����� ������������
��� ������������� ��� ���� ��������.

����� `forward_pass` ���������� ������ ��������� ��������� �� ������� ����������� `input`
� ���������� ������������ ������������� ��� ������� �������.

� ������ `backpropagation` ���������� �������� ��������� ��������������� ������.
� �������� ���������� �� ������ ����������� `input`, ���������� ����� `y`,
��������� �������� �������� `learning_rate`, ����������� ������������� � ������� �������
(�� ���������: �������� � ������������ ������� ������).

---

####func.cpp func.h
� ���� ������ ������� � ����������� �������, ������������ �� ���������
��� ������ ���������.

---

####body.cpp body.h
������� `reading` ���������� ���������� ����������� � ���������� ������� �� ������������� �����.

� ������� `learning` ���������� �������� �� `epoch` ��������� �������� �� ������� ��������
����������� `input`.

---

####main.cpp
���������� ��������� ���������� ���� � �������� �������� �������� � `epoch` � `learning_rate` ��������������.

��������� �������� ����������� �� ������-����� `nums`.
��������� �� ��������� ��������� ����������� � `net`.

---

####����������� ������ ���������
�������� ��������� ���������: �������� ��������, ���������� ���� �������� � ��������� ����
(���������� �������� � ������ ����) ���������� ��������������� � **main.cpp**.

��� ������� ����� �������� ��������� ������������� ������� � ������� ������� ������.
��� ����� ���������� ������� � ����������� ��������������� ������� � �� ����������� �
���������� � �������� ���������� � ����������� ��������� � ����� `backpropagation`.