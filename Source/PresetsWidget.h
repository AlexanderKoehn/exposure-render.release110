#pragma once

#include <QtGui>
#include <QtXml\qdom.h>

#include "TransferFunction.h"

class QPresetItem : public QListWidgetItem
{
public:
	QPresetItem(QListWidget* pListWidget, const QString& Name, void* pData) :
		QListWidgetItem(pListWidget),
		m_pData(pData)
	{
		setText(Name);
	}

	void* m_pData;
};

class QPresetsWidget : public QGroupBox
{
    Q_OBJECT

public:
    QPresetsWidget(QWidget* pParent = NULL);
	~QPresetsWidget(void);

	virtual QSize sizeHint() const { return QSize(10, 10); }

protected slots:
	void CreateConnections(void);
	void CreateUI(void);
	void LoadPresetsFromFile(const bool& ChoosePath = false);
	void SavePresetsToFile(const bool& ChoosePath = false);
	void UpdatePresetsList(void);
	void OnPresetSelectionChanged(void);
	void OnLoadPreset(void);
	void OnRemovePreset(void);
	void OnSavePreset(void);
	void OnLoadPresets(void);
	void OnSavePresets(void);
	void OnDummy(void);
	void OnPresetNameChanged(const QString& Text);
	void OnPresetItemChanged(QListWidgetItem* pWidgetItem);

protected:
	QGridLayout				m_MainLayout;
	QComboBox				m_PresetName;
	QPushButton				m_LoadPreset;
	QPushButton				m_SavePreset;
	QPushButton				m_RemovePreset;
	QPushButton				m_LoadPresets;
	QPushButton				m_SavePresets;
	QPushButton				m_Dummy;
	QTransferFunctionList	m_TransferFunctions;
};