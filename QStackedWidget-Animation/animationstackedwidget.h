#ifndef ANIMATIONSTACKEDWIDGET_H
#define ANIMATIONSTACKEDWIDGET_H

#include <QPainter>
#include <QVariant>
#include <QMouseEvent>
#include <QStackedWidget>
#include <QPropertyAnimation>

class AnimationStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    enum AnimationType
    {
        TopToBottom,
        BottomToTop,
        LeftToRight,
        RightToLeft
    };

    explicit AnimationStackedWidget(QWidget *parent = 0);
	virtual ~AnimationStackedWidget();

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

	void start(int index);
	void setNext(bool);
    void setLength(int length, AnimationType type);
	void setWidgets(QList<QWidget*>);
	void setPos(QList<QPoint>);
private slots:
    void valueChanged(const QVariant &value);
    void animationFinished();
signals:
	void sigGetWidgets(int);
protected:
    virtual void paintEvent(QPaintEvent *event);
    void renderPreviousWidget(QPainter &painter, QTransform &transform);
    void renderCurrentWidget(QPainter &painter, QTransform &transform);
private:
    bool m_isAnimating;//������������
    float m_currentValue;//���������仯��ֵ
    int m_currentIndex, m_previousIndex;//��ǰ��ǰһ����������
	int m_iWidth;//���ڿ��
	bool m_bRight;//�Ƿ������ƶ�
    AnimationType m_type;
    QPropertyAnimation *m_animation;//�ƶ�����
	QPoint m_startPos;//��갴������
	QList<QWidget*> m_lstWs;//С���ڵ�ַ
	QList<QPoint> m_lstPos;//����С��������
	bool m_bUpdate;//�Ƿ���Խ����ػ��¼�
	bool m_Oncepress;//ÿ����갴��ʱ���н�����������
	bool m_canMove;//��갴��ʱ���������δ����������ƶ����ͷ���Ч
	int m_savePreviousIndex;//��������ƶ�ʱ��һ����������
};

#endif // ANIMATIONSTACKEDWIDGET_H
